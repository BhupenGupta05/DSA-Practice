// In Android (the popular Google mobile operating system), the executable files storing apps on devices are called "APKs". 
// And each APK contains something called a "Manifest" which stores which devices it is compatible with. 
// So for example, it might say needs a specific Android version, or needs a GPS chip. 
// In this question, we are only going to think about the Android version requirements in the Manifest.
// There are two values minSDKVersion and maxSDKVersion. 
// Each of these is optional, and inclusive.
// An app developer can upload multiple APKs for their app to the Play Store, each with a different manifest. 
// For example, they might have three APKs:
// APK		Min SDK Version	Max SDK Version
// APK A	      4				        -
// APK B	      -			        	16
// APK C	      7				        10
// Now, on Google Play you can have more than one APK per App, and we need to decide which one to deliver. 
// So you could have A,B, and C. 
// As part of this process we need to split up the space of all phones to which APKs they match.
// We want to divide the integer list of SDK versions into intervals that match the same APKs. 
// So for this set we want to produce:
// (<=3), (4-6), (7-10), (11-16), (>=17)
// This is because <=3 matches only APK B, then (4-6) matches APK A & B, but not C, etc.


#include <bits/stdc++.h>

using namespace std;

struct APK {
    string name;
    int min_sdk;   
    int max_sdk;  
};

vector<string> computeSDKIntervals(vector<APK>& apks) {
    set<int> cuts;
    
    for(auto apk: apks) {
        if(apk.min_sdk != -1) {
            cuts.insert(apk.min_sdk);
        }
        if(apk.max_sdk != -1) {
            cuts.insert(apk.max_sdk+1);
        }
    }
    
    vector<int> sortedCuts(cuts.begin(), cuts.end());
    int n = sortedCuts.size();
    
    vector<string> intervals;
    
    for(int i=0; i<n; i++) {
        int cut = sortedCuts[i];
        
        if(i == 0) {
            intervals.push_back("<=" + to_string(cut-1));
        }
        
        if(i + 1 < n) {
            int next_cut = sortedCuts[i+1];
            intervals.push_back(to_string(cut) + "-" + to_string(next_cut-1));
        } else {
            intervals.push_back(">=" + to_string(cut));
        }
    }
    return intervals;
    
}

int main()
{
    vector<APK> apks = {
        {"APK A", 4,  -1},   // min=4, no max
        {"APK B", -1, 16},   // no min, max=16
        {"APK C", 7,  10},   // min=7, max=10
    };
    
    vector<string> ans = computeSDKIntervals(apks);
    
    for(auto ch: ans) {
        cout<<ch<<", ";
    }

    return 0;
}