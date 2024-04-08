class Solution
{
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
         for(int i=0;i<10000;i++)
        {
            int l = students[0];
            int k = sandwiches[0];
            if( l != k )
            {
                students.erase(students.begin());
                students.push_back(l);
            }
            else
            {
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
            }
            if(students.size()== 0)break;
        }
        return students.size();
    }
};