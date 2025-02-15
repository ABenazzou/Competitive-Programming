from autokattis import OpenKattis
import os
import json


if __name__ == '__main__':
    kt = OpenKattis(os.getenv("KATTIS_EMAIL"), os.getenv("KATTIS_PASSWORD"))

    total_problems_attempted = len(kt.problems(show_partial=True, show_tried=True, show_untried=False))
    total_problems_accepted = len(kt.problems(show_partial=False, show_tried=False, show_untried=False))
    total_problems_failed = total_problems_attempted - total_problems_accepted

    with open("./data.json", "w", encoding="UTF-8") as f:
        json.dump(
            {
                "total": total_problems_attempted,
                "accepted": total_problems_accepted,
                "rejected": total_problems_failed,
            },
            f
        )
    print("Saved: data.json")