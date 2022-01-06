#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    // Initilization
    unordered_map<string, unordered_set<string>> ActualMail;
    // Validate
    for (size_t i = 0; i < emails.size(); ++i) {
      size_t Loc = emails[i].find('@');
      const string& LocalName = emails[i].substr(0, Loc);
      const string& DomainName = emails[i].substr(Loc + 1);

      string LocalName_Actual;
      LocalName_Actual.reserve(LocalName.size());
      for (const auto& C : LocalName)
        if (C == '+')
          break;
        else if (C == '.')
          continue;
        else
          LocalName_Actual.push_back(C);

      cout << LocalName_Actual << "@" << DomainName << endl;

      ActualMail[DomainName].insert(LocalName_Actual);
    }
    // Yay!
    int Result = 0;
    for (const auto& [K, V] : ActualMail) Result += V.size();
    return Result;
  }
};
