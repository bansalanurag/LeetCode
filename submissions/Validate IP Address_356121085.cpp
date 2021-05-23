class Solution {
public:
    
    bool leadingSpace(string S) {
        if (S.length() == 1 && S[0] == '0') return false;
        if (S[0] == '0') return true;
        for (char c : S) if (!(c >= '0' && c <= '9')) return true;
        return false;
    }
    
    bool checkValidIpv4(string ip) {
        vector<string> octets;
        int i = 0, j = 0;
        for (; i < ip.size(); i++) {
            while (i < ip.size() && ip[i] != '.') i++;       
            if (i == j) return false;            
            octets.push_back(ip.substr(j, i - j));
            j = i + 1;
        }
        
        if (octets.size() != 4) return false;
        
        for (string s : octets) {
            if (s.length() < 1 || s.length() > 3) return false;
            if (leadingSpace(s)) return false;
            if (stoi(s) > 255 || stoi(s) < 0) return false;
        }
        return true;
    }
    
    bool checkValidIpv6(string ip) {
        vector<string> octets;
        int i = 0, j = 0;
        for (; i < ip.size(); i++) {
            while (i < ip.size() && ip[i] != ':') i++;
            if (i == j) return false;            
            octets.push_back(ip.substr(j, i - j));
            j = i + 1;
        }
        
        if (octets.size() != 8) return false;
        
        for (string s : octets) {
            if (s.length() < 1 || s.length() > 4) return false;
            for (char c : s) {
                if (!((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c >= '0' && c <= '9')))
                    return false;                    
            }
        }
        return true;   
    }
    
    int CategorizeIP(string IP) {
        int seperator = 0;
        seperator = count(IP.begin(), IP.end(), '.');
        
        if (seperator == 3) {
            return 1;
        } else if (seperator == 0) {
            seperator = count(IP.begin(), IP.end(), ':');
            if (seperator == 7) {
                return 2;
            } 
        }
        return 0;
    }
    
    string validIPAddress(string IP) {
        int isIpv4 = CategorizeIP(IP);
        switch (isIpv4) {
            case 0: return "Neither";
            case 1: return (checkValidIpv4(IP)) ? "IPv4" : "Neither";
            case 2: return (checkValidIpv6(IP)) ? "IPv6" : "Neither";
        }
        
        return "Neither";
    }
};
