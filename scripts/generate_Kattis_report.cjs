const fs = require('fs-extra');
const utils = require('./utils')

async function fetchData() {
    try {
        let result = JSON.parse(fs.readFileSync('./data.json'));

        return { accepted: result.accepted, rejected: result.rejected, total: result.total };
    } catch (err) {
        console.error("Error fetching data:", err);
        return null;
    }
}


(async () => {
    const data = await fetchData();
    if (!data) return;

    const svgFile = await utils.generateDonutChart(data, "out/Kattis_donut_chart.svg");
    console.log(`Saved: ${svgFile}`);
})();
