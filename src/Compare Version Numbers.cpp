//Compare Version Numbers
/*Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37*/
class Solution {
public:
    int compareVersion(string version1, string version2) { 
 	//	cout<<"string:"<<version1<<" "<<version2<<endl;
		int pos1=-1,pos2=-1,i1,i2;

		string s1,s2,sub1,sub2;
		if(version1.empty() && version2.empty())
		    return 0;
		if(version1.empty())
		    i1=0;
		if(version2.empty())
		    i2=0;
		
		
		if(version1.find_first_of('.') != string::npos){
			s1 = version1.substr(0,version1.find_first_of('.')+1);
			pos1 = version1.find_first_of('.');
			sub1 = version1.substr(pos1+1);
			i1 = atoi(s1.c_str());
		}else{
			if(!version1.empty()){
				s1=version1;
				pos1 = version1.size();
				sub1 = "";
				i1 = atoi(s1.c_str());
			}
		}
		//i1 = atoi(s1.c_str());
	
		if(version2.find_first_of('.') != string::npos){
			s2 = version2.substr(0,version2.find_first_of('.')+1);
			pos2 = version2.find_first_of('.');
			sub2 = version2.substr(pos2+1);
			i2 = atoi(s2.c_str());
		}else{
			if(!version2.empty()){
				s2=version2;
				pos2 = version2.size();
				sub2 = "";
				i2 = atoi(s2.c_str());
			}
		}
		//i2 = atoi(s2.c_str());

	//	cout<<i1<<" "<<i2<<endl;
		if(i1 > i2)
			return 1;
		else if(i1 == i2){
		   // cout<<"sub1:"<<sub1<<" sub2:"<<sub2<<endl; 
			return compareVersion(sub1,sub2);
		}else
			return -1;
		
    }
};