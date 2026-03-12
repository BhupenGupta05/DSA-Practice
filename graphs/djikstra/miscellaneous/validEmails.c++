// Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.

// For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
// If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule does not apply to domain names.

// For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
// If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. Note that this rule does not apply to domain names.

// For example, "m.y+name@email.com" will be forwarded to "my@email.com".
// It is possible to use both of these rules at the same time.

// Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that actually receive mails.


#include <bits/stdc++.h>

using namespace std;

int numUniqueEmails(vector<string>& emails) {
	int n = emails.size();
	unordered_set<string> uniqueEmails;

	for(int i=0; i<n; i++) {
		int atPos = emails[i].find('@');
		string localName = emails[i].substr(0, atPos);
		string domainName = emails[i].substr(atPos+1);

		localName.erase(remove(localName.begin(), localName.end(), '.'), localName.end());

		int plusPos = localName.find('+');
		if(plusPos != string::npos) {
			localName = localName.substr(0, plusPos);
		}


		uniqueEmails.insert(localName + '@' + domainName);

	}

	return uniqueEmails.size();

}

int main()
{
	vector<string> emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
	int ans = numUniqueEmails(emails);

	cout<<ans;

	return 0;
}