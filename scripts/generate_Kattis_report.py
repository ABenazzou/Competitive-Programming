from autokattis import OpenKattis
import matplotlib.pyplot as plt
import os


def generate_donut_chart(accepted, rejected, output_file="Kattis_donut_chart.svg"):
    sizes = [accepted, rejected]
    labels = ["Accepted", "Rejected"]
    colors = ["green", "red"]
    
    fig, ax = plt.subplots(figsize=(6, 6))
    wedges, _, autotexts = ax.pie(
        sizes, colors=colors, startangle=90, wedgeprops={'edgecolor': 'white'},
        autopct=lambda p: f'{int(p * sum(sizes) / 100)}'
    )
    
    center_circle = plt.Circle((0, 0), 0.70, fc='white')
    fig.gca().add_artist(center_circle)
    
    total_color = colors[0] if accepted >= rejected else colors [1]
    
    for idx, text in enumerate(autotexts):
        text.set_color(colors[idx])
        text.set_fontsize(14)
        text.set_weight("bold")
    
    ax.legend(wedges, labels, title="Categories", loc="center left", bbox_to_anchor=(1, 0, 0.5, 1))
    
    total = sum(sizes)
    total_text = ax.text(0, 0, f"Total:\n{total}", ha='center', va='center', fontsize=14, fontweight='bold')
    total_text.set_color(total_color)
    
    plt.axis('equal') 
    plt.savefig(output_file, format="svg", bbox_inches="tight")
    plt.close()
    
    return output_file


if __name__ == '__main__':
    kt = OpenKattis(os.getenv("KATTIS_EMAIL"), os.getenv("KATTIS_PASSWORD"))

    total_problems_attempted = len(kt.problems(show_partial=True, show_tried=True, show_untried=False))
    total_problems_accepted = len(kt.problems(show_partial=False, show_tried=False, show_untried=False))
    total_problems_failed = total_problems_attempted - total_problems_accepted

    output = generate_donut_chart(total_problems_accepted, total_problems_failed)
    print(f"Saved: {output}")
