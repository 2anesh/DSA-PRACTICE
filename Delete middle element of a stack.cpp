class Solution

{

public:

 //Function to delete middle element of a stack.

 void deleteMid(stack<int>&s, int sizeOfStack)

  {

   vector<int> vec;

   int n=ceil((sizeOfStack+1)/2.0);//you need to remove top n elements to reach to the middle one.

   while(n--)

   {

    vec.push_back(s.top());

    s.pop();

   }

  vec.pop_back();//remove the middle-most element which will be the last one in the array.

  for(int i=vec.size()-1;i>=0;i--)

   s.push(vec[i]);//insert back all the elements before middle element

 }

};
