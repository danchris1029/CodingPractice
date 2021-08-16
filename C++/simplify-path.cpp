//Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

class Solution {
public:
    string simplifyPath(string path) {
        string res = "",
                dir = "";
        int dot = 0;
        vector<string> directs;
        
        for(int i = 0; i < path.length(); i++){
            
            // slash clears current directory or periods 
            if(path[i] == '/'){
                if(dot && dir.length()){
                    string dots = "";
                    for(int i = 0; i < dot; i++)
                        dots += ".";
                    dir += dots;
                }
                else if(dot == 2 && directs.size() > 0)
                    directs.pop_back();
                else if(dot == 3)
                    directs.push_back("...");
                if(dir.length())
                    directs.push_back(dir);
                dot = 0;
                dir = "";
                continue;
            }
            else if(path[i] == '.')
                dot++;
            else{
                // watch out for hidden periods behind directory name
                if(dot){
                    string dots = "";
                    for(int i = 0; i < dot; i++)
                        dots += ".";
                    dir = dots;
                    dot = 0;
                }
                dir += path[i];
            }
                
        }
        // last check after loop
        if(dot == 2 && directs.size())
            directs.pop_back();
        if(dot == 3)
            directs.push_back("...");
        if(dir.length())
            directs.push_back(dir);
        
        // make final string
        if(directs.size()){
            for(auto dir:directs){
                res += "/";
                res += dir;
            }  
        }
        else
            res = "/";
        
        return res;
    }
};
