// A. Diamond Miner
/*
Diamond Miner is a game that is similar to Gold Miner, but there are n miners instead of 1 in this game.

The mining area can be described as a plane. The n miners can be regarded as n points on the y-axis.
There are n diamond mines in the mining area. We can regard them as n points on the x-axis.
For some reason, no miners or diamond mines can be at the origin (point (0,0)).

Every miner should mine exactly one diamond mine. Every miner has a hook, which can be used to mine a diamond mine.
If a miner at the point (a,b) uses his hook to mine a diamond mine at the point (c,d),
he will spend sqrt((a−c)^2+(b−d)^2) energy to mine it (the distance between these points). The miners can't move or help each other.

The object of this game is to minimize the sum of the energy that miners spend. Can you find this minimum?

Each of the next 2n lines contains two space-separated integers x (−10^8≤x≤10^8) and y (−10^8≤y≤10^8)
*/

/*
N goldMiners and N goldMines

goldMiners are on the y axis, and the goldMines are on the x axis

Every miner has to mine some mines (we have to assign every miner to a mine), what will be the energy
required for a miner to mine a mine is actually the distance between that mine and that miner
simply drawing straight lines from the y axis to the x axis

The task is to assign a miner with a mine, and just assign all the distances such that we just have to
minimize the total energy spent

We have to accumulate all the distances such that we have to assign each mine to a miner such that the
accumulative sum of the distances or the energy is minimized

Algo:

    In essence we have to find out the diagonal formed between the axis

    Distance will remain same, so we can just flip points in x and y coordinates
    (as we are just finding the length of the diagonal)

    It might happen we have an intersection between two lines, as it can increase the distance

        we want to avoid any intersections
*/

void solve() {
    int n;
    cin >> n;
    vector<ll>a, b;
    for (int i = 0; i < 2 * n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x == 0) b.push_back(abs(y)); // find x coordinates
        else a.push_back(abs(x)); // find y coordinates
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    double ans = 0;
    for (int i = 1; i < n; ++i) {
        ll x = a[i] * a [i] + b[i] * b[i];
        ans += (double) sqrt(x);
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    for (int i = 0; i <= t; ++i) {
        solve();
    }
    return 1;
}