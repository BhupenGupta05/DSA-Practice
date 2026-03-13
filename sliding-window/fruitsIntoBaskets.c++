// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.


int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    unordered_map<int, int> umap;
    int start = 0;
    int maxLen = 0;

    if (n == 0 || n == 1)
        return n;

    for (int end = 0; end < n; end++)
    {
        umap[fruits[end]]++;

        if (umap.size() <= 2)
        {
            maxLen = max(maxLen, end - start + 1);
        }

        while (umap.size() > 2)
        {
            umap[fruits[start]]--;
            if (umap[fruits[start]] == 0)
            {
                umap.erase(fruits[start]);
            }
            start++;
        }
    }
    return maxLen;
}

int main()
{
    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << totalFruit(fruits) << endl;

    return 0;
}