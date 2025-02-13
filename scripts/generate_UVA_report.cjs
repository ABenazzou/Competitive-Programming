const Vjudge = require('vjudge-api');
const fs = require('fs-extra');
const D3Node = require('d3-node');

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

async function generateDonutChart(data) {
    const d3n = new D3Node();
    const d3 = d3n.d3;

    const width = 500, height = 500, radius = Math.min(width, height) / 2;
    const svg = d3n.createSVG(width, height + 40);
    const g = svg.append("g").attr("transform", `translate(${width / 2}, ${height / 2})`);

    const pie = d3.pie().value(d => d.count);
    const arc = d3.arc().innerRadius(radius * 0.5).outerRadius(radius);
    const color = d3.scaleOrdinal(["green", "red"]);

    const dataReady = pie([
        { category: "Accepted", count: data.accepted },
        { category: "Rejected", count: data.rejected }
    ]);

    g.selectAll("path")
        .data(dataReady)
        .enter().append("path")
        .attr("d", arc)
        .attr("fill", d => color(d.data.category))
        .attr("stroke", "white")
        .style("stroke-width", "2px");

    g.selectAll("text")
        .data(dataReady)
        .enter().append("text")
        .attr("transform", d => `translate(${arc.centroid(d)})`)
        .attr("text-anchor", "middle")
        .attr("font-size", "16px")
        .attr("fill", "white") 
        .text(d => d.data.count);

    const legend = svg.append("g").attr("transform", `translate(${width / 2 - 50}, ${height + 20})`);
    const labels = ["Accepted", "Rejected"];
    labels.forEach((label, i) => {
        legend.append("rect")
            .attr("x", i * 100 - 40)
            .attr("y", 0)
            .attr("width", 20)
            .attr("height", 20)
            .attr("fill", color(label));

        legend.append("text")
            .attr("x", i * 100 - 10)
            .attr("y", 15)
            .attr("font-size", "16px")
            .attr("fill", color(label))
            .text(label);
    });

    const outputFilePath = "UVA_donut_chart.svg";
    fs.writeFileSync(outputFilePath, d3n.svgString());

    return outputFilePath;
}

(async () => {
    const data = await fetchData();
    if (!data) return;

    const svgFile = await generateDonutChart(data);
<<<<<<< HEAD
<<<<<<< HEAD
    console.log(`Saved: ${svgFile}`)
=======
>>>>>>> f639b6e (Update and rename generate_UVA_report.mjs to generate_UVA_report.cjs)
=======
    console.log(`Saved: ${svgFile}`)
>>>>>>> a6fdada (Update generate_UVA_report.cjs)
})();
