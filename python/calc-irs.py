# ---------------- Interactive IRS 2025 Calculator (with IRS Jovem) ----------------

IAS_2025 = 522.50
IRS_JOVEM_LIMIT_MULTIPLIER = 55
SPECIFIC_DEDUCTION_CAT_A_2025 = 4462.15

# 2025 IRS brackets (marginal rates)
IRS_2025_BRACKETS = [
    (8059.00, 0.13),
    (12160.00, 0.165),
    (17233.00, 0.22),
    (22306.00, 0.25),
    (28400.00, 0.32),
    (41629.00, 0.355),
    (44987.00, 0.435),
    (83696.00, 0.45),
    (float("inf"), 0.48),
]

def progressive_tax(amount):
    """Calculate progressive tax according to 2025 brackets."""
    if amount <= 0:
        return 0.0
    tax = 0.0
    lower = 0.0
    for limit, rate in IRS_2025_BRACKETS:
        span = min(amount, limit) - lower
        if span > 0:
            tax += span * rate
            lower += span
        if lower >= amount:
            break
    return tax

def get_irs_jovem_percentage(year: int) -> float:
    """Return exemption percentage for the given IRS Jovem year."""
    mapping = {1: 1.00, 2: 0.75, 3: 0.75, 4: 0.75, 5: 0.50}
    return mapping.get(year, 0.0)

def calculate_irs_2025_with_irs_jovem(gross_income: float, jovem_year: int):
    """Main IRS calculation logic."""
    jovem_limit = IRS_JOVEM_LIMIT_MULTIPLIER * IAS_2025
    jovem_percent = get_irs_jovem_percentage(jovem_year)
    jovem_exempt = min(gross_income, jovem_limit) * jovem_percent

    taxable_income = max(0.0, gross_income - jovem_exempt - SPECIFIC_DEDUCTION_CAT_A_2025)
    tax_due = progressive_tax(taxable_income)
    effective_rate = (tax_due / gross_income) * 100 if gross_income > 0 else 0

    print("\n------ IRS 2025 Simulation (with IRS Jovem) ------")
    print(f"Annual Gross Income:         €{gross_income:,.2f}")
    print(f"IRS Jovem Year:              {jovem_year}º ano")
    print(f"IRS Jovem Limit (55xIAS):    €{jovem_limit:,.2f}")
    print(f"IRS Jovem Exempt Percentage: {jovem_percent*100:.0f}%")
    print(f"IRS Jovem Exempt Amount:     €{jovem_exempt:,.2f}")
    print(f"Taxable after Deductions:    €{taxable_income:,.2f}")
    print(f"Estimated Annual IRS:        €{tax_due:,.2f}")
    print(f"Effective Tax Rate:          {effective_rate:.2f}%")
    print(f"Approx. Monthly (14 months): €{tax_due/14:,.2f}")
    print("---------------------------------------------------\n")

# -------------------- MAIN PROGRAM --------------------

try:
    gross_income = float(input("Enter your annual gross salary (€): ").strip().replace(",", "."))
    jovem_year = int(input("Enter your IRS Jovem year (1–5): ").strip())

    calculate_irs_2025_with_irs_jovem(gross_income, jovem_year)

except ValueError:
    print("⚠️ Invalid input. Please enter valid numeric values.")
