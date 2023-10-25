typedef long double gtype;
const gtype pi = M_PI;
typedef complex<gtype> point;
typedef complex<gtype> point;
#define x real()
#define y imag()
#define polar(r, t) polar((gtype) (r), (t))
// vector
#define rot(v, t) ( (v) * polar(1, t) )
#define crs(a, b) ( (conj(a) * (b)).y )
#define dot(a, b) ( (conj(a) * (b)).x )
#define pntLinDist(a, b, p) ( abs(crs((b)-(a), (p)-(a)) / abs((b)-(a))) )
bool cmp_point(point const& p1, point const& p2) {
    return p1.x == p2.x ? (p1.y < p2.y) : (p1.x < p2.x);
}
// O(n) - rotating calipers (works on a ccw closed convex hull)
gtype rotatingCalipers(vector<point> &ps) {
    int aI = 0, bI = 0;
    for (size_t i = 1; i < ps.size(); ++i)
        aI = (ps[i].y < ps[aI].y ? i : aI), bI = (ps[i].y > ps[bI].y ? i : bI);
    gtype minWidth = ps[bI].y - ps[aI].y, aAng, bAng;
    point aV = point(1, 0), bV = point(-1, 0);
    for (gtype ang = 0; ang < pi; ang += min(aAng, bAng)) {
        aAng = acos(dot(ps[aI + 1] - ps[aI], aV)
            / abs(aV) / abs(ps[aI + 1] - ps[aI]));
        bAng = acos(dot(ps[bI + 1] - ps[bI], bV)
            / abs(bV) / abs(ps[bI + 1] - ps[bI]));
        aV = rot(aV, min(aAng, bAng)), bV = rot(bV, min(aAng, bAng));
        if (aAng < bAng)
            minWidth = min(minWidth, pntLinDist(ps[aI], ps[aI] + aV, ps[bI]))
            , aI = (aI + 1) % (ps.size() - 1);
        else
            minWidth = min(minWidth, pntLinDist(ps[bI], ps[bI] + bV, ps[aI]))
            , bI = (bI + 1) % (ps.size() - 1);
    }
    return minWidth;
}