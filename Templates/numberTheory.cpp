#define ld long double
const ll N_ = 300007;
ll facts[N_];
ll invfacts[N_];

ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b) {
    return (a % mod + b % mod) % mod;
}
ll sub(ll a, ll b)
{
    return (mod + a % mod - b % mod) % mod;
}
ld powe(ld a, int b) {
    if (b == 0) return 1;
    if (b % 2) return a * powe(a * a, b / 2);
    return powe(a * a, b / 2);
}
ll expo(ll base, ll pow) {
    if (pow == 0) return 1;
    ll half = expo(base, pow / 2);
    if (pow % 2 == 0) return mul(half, half);
    return mul(half, mul(half, base));
}
ll divi(ll a, ll b)
{
    return mul(a, expo(b, mod - 2));
}
void makef() {
    facts[0] = 1;
    for (ll i = 1; i < N_ - 1; i++)
        facts[i] = mul(facts[i - 1], i);

    invfacts[N_ - 2] = divi(1ll, facts[N_ - 2]);
    for (ll i = N_ - 3; i >= 0; i--)
        invfacts[i] = mul(invfacts[i + 1], i + 1);
}

ll modInv(ll x) {
    return expo(x, mod - 2);
}

ll nCk(ll n, ll k) {
    if (n < k)
        return 0;
    if (n == k)
        return 1;
    return mul(facts[n], mul(invfacts[k], invfacts[n - k]));
}
