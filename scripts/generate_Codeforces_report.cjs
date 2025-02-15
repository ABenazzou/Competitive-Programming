const utils = require('./utils')
const options = { un: "AdnaneB" };

async function fetchData() {
    try {
        let result = await fetch(`https://codeforces.com/api/user.status?handle=${options.un}`)
        let accepted = 0, rejected = 0;
        const json = await result.json();
        let problemsMap = new Map(); 

        json.result.forEach(problem => {
            if (problem.hasOwnProperty("verdict") && problem.verdict == "OK") {
                problemsMap.set(problem.problem.name, "OK");
            }
            else if (!problemsMap.has(problem.problem.name)) {
                problemsMap.set(problem.problem.name, "NOK");
            } 
        });
        
        problemsMap.forEach((value, _)=> {
            value == "OK" ? accepted ++ : rejected ++;
        });

        return { accepted: accepted, rejected: rejected, total: accepted + rejected };
    } catch (err) {
        console.error("Error fetching data:", err);
        return null;
    }
}


(async () => {
    const data = await fetchData();
    if (!data) return;

    const svgFile = await utils.generateDonutChart(data, "out/Codeforces_donut_chart.svg");
    console.log(`Saved: ${svgFile}`);
})();
