const Vjudge = require('vjudge-api');
const utils = require('./utils');
const options = { un: "AdnaneBen" };

async function fetchData() {
    try {
        let result = await Vjudge.solve_count(options);
        let acceptedUVA = result["acRecords"]["UVA"].length;
        let rejectedUVA = result["failRecords"]["UVA"].length;
        return { accepted: acceptedUVA, rejected: rejectedUVA, total: acceptedUVA + rejectedUVA };
    } catch (err) {
        console.error("Error fetching data:", err);
        return null;
    }
}

(async () => {
    const data = await fetchData();
    if (!data) return;

    const svgFile = await utils.generateDonutChart(data, "out/UVA_donut_chart.svg");
    console.log(`Saved: ${svgFile}`);
})();
