// Copyright (c) 2017 The Martkist Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.



#include <string>
#include <vector>
#include <map>

vector<SecureString> vGovernanceKeys;
CCriticalSection cs_vGovernanceKeys;

/*
	
	Notes:
	
	- Users will configure their keys, something like this:

	martkist.conf:

		addgovkey=PrivKey1:name1 #comments
		addgovkey=PrivKey2:name2 #comments

	- Each of these will be securely secured in memory, then parsed and the secret will be used temporarily while 
		creating a new goverance object which requires a signature
*/

/*
	Simple contained to also hold the key and key name.
*/
class CGovernanceKey
{
private:
	SecureString strName;
	SecureString strKey;

public:
	CGovernanceKey::CGovernanceKey(SecureString& strKeyIn, SecureString& strNameIn) {strName = strNameIn; strKey = strKeyIn;}

	bool GetKey(CMartkistSecret& secret)
	{
	    return secret.SetString(vecTokenized[0]);
	}

	std::string GetName()
	{
		return strName;
	}
};

class CGovernanceKeyManager
{
	static bool CGovernanceKeyManager::InitGovernanceKeys(std::string strError);
};