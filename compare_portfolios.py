import json
import numpy as np
import sys

def calculate_percentage_error(actual_value, expected_value):
    if expected_value == 0:
        return 0
    return (abs(actual_value - expected_value) / expected_value) * 100

def compare_portfolios(file1, file2):
    # Charge les fichiers JSON
    with open(file1, 'r') as f1:
        portfolio1 = json.load(f1)

    with open(file2, 'r') as f2:
        portfolio2 = json.load(f2)

    # Parcours les dates et compare les prix et deltas
    for pos1, pos2 in zip(portfolio1['positions'], portfolio2['positions']):
        date = pos1['date']
        price1 = pos1['price']
        price2 = pos2['price']
        price_std_dev1 = pos1['priceStdDev']
        price_std_dev2 = pos2['priceStdDev']

        # Vérification des prix
        if price2 >= price1 - 4 * price_std_dev1 and price2 <= price1 + 4 * price_std_dev1:
            print(f"Date {date}: OK (Price within range)")
        else:
            print(f"Date {date}: Pas Bon (Price out of range)")

        # Calcul de l'écart en pourcentage
        price_percentage_error = calculate_percentage_error(price2, price1)
        print(f"Date {date}: Price Percentage Error: {price_percentage_error:.2f}%")

        # Vérification des deltas
        deltas1 = np.array(pos1['deltas'])
        deltas2 = np.array(pos2['deltas'])

        if np.allclose(deltas1, deltas2, atol=1e-5):
            print(f"Date {date}: OK (Deltas within range)")
        else:
            print(f"Date {date}: Pas Bon (Deltas out of range)")

        # Calcul de l'écart en pourcentage des deltas
        delta_percentage_error = np.linalg.norm(deltas2 - deltas1) / np.linalg.norm(deltas1) * 100
        print(f"Date {date}: Delta Percentage Error: {delta_percentage_error:.2f}%")

        # Calcul de l'écart de portefeuille
        portfolio_value1 = pos1['portfolioValue']
        portfolio_value2 = pos2['portfolioValue']
        portfolio_percentage_error = calculate_percentage_error(portfolio_value2, portfolio_value1)
        print(f"Date {date}: Portfolio Value Percentage Error: {portfolio_percentage_error:.2f}%")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python compare_portfolios.py <portfolio1.json> <portfolio2.json>")
        sys.exit(1)

    file1 = sys.argv[1]
    file2 = sys.argv[2]

    compare_portfolios(file1, file2)
