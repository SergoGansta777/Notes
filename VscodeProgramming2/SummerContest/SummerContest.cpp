#include <bits/stdc++.h>

using namespace std;

    pair<long long, long long> start_point1 = {0, 0};
double PolarAngle(pair<long long, long long> p)
{
  return atan2(1.0*p.second,1.0*p.first);
}
bool cmp (pair<long long,long long> a, pair<long long, long long> b) {
    long long product = a.first * b.second - a.second * b.first;
    if (product == 0)
    {
        return pow(a.first, 2) + pow(a.second, 2) < pow(b.first, 2) + pow(b.second, 2);
    }
	return product > 0;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<long long , long long> > points(n);
    long long start_point = 0;
    for(int i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        points[i] = {x, y};
        if(points[i].second < points[start_point].second or points[i].second == points[start_point].second and points[i].first > points[start_point].first)
        {
            start_point = i;
        }
    }

    pair<long long, long long> tmp = points[0];
    points[0] = start_point1 = points[start_point];
    points[start_point] = tmp;
    for(int i = 0; i<points.size(); i++)
    {
        points[i].first -= start_point1.first;
        points[i].second -= start_point1.second;
    }
    sort(points.begin() + 1, points.end(), &cmp);
     vector<int> indexs;
     indexs.push_back(0);
     indexs.push_back(1);
     for(int i = 2; i < points.size(); i++)
     {

        long long x1 = points[indexs[indexs.size()-1]].first - points[indexs[indexs.size()-2]].first;
        long long x2 = points[i].first-points[indexs[indexs.size()-1]].first;
        long long y1 = points[indexs[indexs.size()-1]].second - points[indexs[indexs.size()-2]].second;
        long long y2 = points[i].second-points[indexs[indexs.size()-1]].second;
        while(indexs.size() >= 2 and (x1 * y2 - x2 * y1 <= 0))
        {
            indexs.pop_back();
            x1 = points[indexs[indexs.size()-1]].first - points[indexs[indexs.size()-2]].first;
            x2 = points[i].first-points[indexs[indexs.size()-1]].first;
            y1 = points[indexs[indexs.size()-1]].second - points[indexs[indexs.size()-2]].second;
            y2 = points[i].second-points[indexs[indexs.size()-1]].second;
        }
        indexs.push_back(i);
     } 
    
    cout << indexs.size() << endl;
    for(int i = indexs.size() - 1; i >= 0; i--)
    {
        cout << points[indexs[i]].first + start_point1.first << " " << points[indexs[i]].second  + start_point1.second<< endl;
    }
     
}