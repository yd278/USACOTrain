#include <bits/stdc++.h>
using namespace std;
struct seg {
    long long L;
    int lP, rP;
    bool dire;  // true : towards, false:backwards
    int uid;
    shared_ptr<seg> left;
    shared_ptr<seg> right;
    long long time;
    void calculateTime(vector<long long>& s) {
        long long mul = (L - 1) / (s[lP] + s[rP]) + 1;
        if (dire)
            time = mul * 2 - 1;
        else
            time = mul * 2;
    }
	~seg(){}
	
};
void process() {
    int n;
    cin >> n;
    vector<long long> s(n);
    vector<long long> p(n);
    vector<long long> ans(n);
    for (auto& x : p) cin >> x;
    for (auto& x : s) cin >> x;
    int uidTop = 0;
    shared_ptr<seg> prev = nullptr;
    bool dir = true;
    map<pair<long long, int>, shared_ptr<seg>> segs;
    for (int i = 0; i < n - 1; i++) {
        shared_ptr<seg> tmp(new seg);
        tmp->L = p[i + 1] - p[i];
        tmp->lP = i;
        tmp->rP = i + 1;
        tmp->dire = dir;
        dir = !dir;
        tmp->uid = uidTop++;
        tmp->left = prev;
        if (prev) {
            prev->right = tmp;
        }
        tmp->calculateTime(s);
        segs.insert(make_pair(make_pair(tmp->time, tmp->uid),tmp));
        prev = tmp;
    }

    while (!segs.empty()) {
        shared_ptr<seg> mid = segs.begin()->second;
        ans[mid->lP] = mid->time;
        ans[mid->rP] = mid->time;
        shared_ptr<seg> lS = mid->left;
        shared_ptr<seg> rS = mid->right;
        segs.erase(segs.begin());
        if (lS!=nullptr && rS!= nullptr) {
            shared_ptr<seg> tmp(new seg);
            tmp->L = lS->L + mid->L + rS->L;
            tmp->lP = lS->lP;
            tmp->rP = rS->rP;
            tmp->dire = lS->dire;
            tmp->uid = uidTop++;
            tmp->left = lS->left;
            if(tmp->left)tmp->left->right = tmp;
            tmp->right = rS->right;
            if(tmp->right)tmp->right->left = tmp;
            tmp->calculateTime(s);
            segs.erase(make_pair(lS->time, lS->uid));
            segs.erase(make_pair(rS->time, rS->uid));
			segs.insert(make_pair(make_pair(tmp->time, tmp->uid),tmp));

        } else {
            if (rS != nullptr) {
				segs.erase(make_pair(rS->time, rS->uid));
				if(rS->right) rS->right->left = nullptr;

            }
			if(lS!=nullptr){
				segs.erase(make_pair(lS->time, lS->uid));
				if(lS->left)lS->left->right = nullptr;

			}
        }
    }

	for(int i = 0; i < n - 1; i++){
		cout<<ans[i]<<" ";
	}
	cout<<ans[n-1]<<"\n";
}
int main() {

    int t;
    cin >> t;
    while (t--) {
        process();
    }
    return 0;
}
