string Solution::fractionToDecimal(int A, int B)
{
    // author : ninja
    // O(n) amortized time iterative solution
    string s;
    long a = A;
    long b = B;
    unordered_map<int, int> ht;
    unordered_map<int, int>::iterator it;

    bool is_negative = (a > 0 && b < 0) || (a < 0 && b > 0);
    a = abs(a);
    b = abs(b);

    s += to_string(a / b);
    a = (a % b) * 10;

    // zero doesnot have a sign
    if (a == 0 && s == "0")
        return s;

    // otherwise add sign
    if (is_negative)
        s = "-" + s;

    // if no reminder then return without any decimal point
    if (a == 0)
        return s;

    // add decimal point
    s += ".";

    // stores start indices of repeting sequence
    int index = s.size();
    while (true)
    {
        if (a == 0)
            return s;

        // if the reminder is found in ht then the sequence repeats itself
        it = ht.find(a);
        if (it != ht.end())
        {
            s.insert(it->second, "(");
            s += ")";
            return s;
        }

        ht[a] = index;
        index++;

        s += to_string(a / b);
        a = (a % b) * 10;
    }
    return s;
}
