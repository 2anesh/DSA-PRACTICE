class Solution
{
    ArrayList<Integer> search(String pat, String txt)
    {
        ArrayList<Integer> list = new ArrayList<>();
        if(txt.indexOf(pat)==-1) {
          list.add(-1);
          return list;
        }
        int index=txt.indexOf(pat);
        list.add(index+1);
        while(index!=-1) {
            index=txt.indexOf(pat, index+1);
            if(index!=-1)
            list.add(index+1);
        }
        return list;
    }
}
