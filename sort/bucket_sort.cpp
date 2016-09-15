/*
To check whether two integers are within distance of t, let bucket[id] be interval [id*(t+1),id*(t+1)+t] to 
cover consecutive t+1 numbers, so if two integer fall into the same bucket, it guarantees the distance constraint. 
Otherwise, they have to fall into neighboring buckets to be able to satisfy the constraint. In code, 
I actually use bkt to store the indices of a[i] values falling into the same bucket. since we compare indices as well, 
if there is a larger index having the same a[i], I will overwrite previous one.
*/


    bool containsNearbyAlmostDuplicate(vector<int>& a, int k, int t) {
        if (t < 0) return false;
        unordered_map<int, unordered_set<int>> bkt; // bkt[id] has the indices of a[i] in [id*(t+1),id*(t+1)+t]
        int n = a.size();
        for (int i = 0; i < n; i++) {
            int id = floor(a[i]/(t+1.0)), idxToErase = -1; 
            if (bkt.count(id)) {
                for (auto x:bkt[id]) {
                    if (i-x <= k) return true;
                    else if (a[x] == a[i]) idxToErase = x;
                }
                // if same value of a[i] with a later index is found
                if (idxToErase >= 0) bkt[id].erase(idxToErase);
            }
            if (bkt.count(id+1))
                for (int x:bkt[id+1]) if (i-x <= k && abs((long)a[i] - (long)a[x]) <= (long)t) return true;
            if (bkt.count(id-1))
                for (int x:bkt[id-1]) if (i-x <= k && abs((long)a[i] - (long)a[x]) <= (long)t) return true;
            bkt[id].insert(i);
        }
        return false;
    }
