import json
import sys

def load_json(filename):
    """ Load JSON file """
    with open(filename, "r") as file:
        return json.load(file)

def is_within_range(value, ref_value, ref_std_dev, threshold=4):
    """ Check if value is within [ref_value - threshold * ref_std_dev, ref_value + threshold * ref_std_dev] """
    lower_bound = ref_value - threshold * ref_std_dev
    upper_bound = ref_value + threshold * ref_std_dev
    return lower_bound <= value <= upper_bound

def compare_portfolios(prof_json, my_json):
    """ Compare professor's portfolio and student's portfolio """
    for prof_entry, my_entry in zip(prof_json, my_json):
        date = prof_entry["date"]
        
        # Check price
        price_check = is_within_range(my_entry["price"], prof_entry["price"], prof_entry["priceStdDev"])
        
        # Check deltas
        deltas_check = all(
            is_within_range(my_delta, prof_delta, prof_std_dev)
            for my_delta, prof_delta, prof_std_dev in zip(my_entry["deltas"], prof_entry["deltas"], prof_entry["deltasStdDev"])
        )
        
        if price_check and deltas_check:
            print(f"Date {date}: OK")
        else:
            print(f"Date {date}: Pas Bon")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python compare_portfolios.py <professor_json> <my_json>")
        sys.exit(1)

    prof_data = load_json(sys.argv[1])
    my_data = load_json(sys.argv[2])
    
    compare_portfolios(prof_data, my_data)
