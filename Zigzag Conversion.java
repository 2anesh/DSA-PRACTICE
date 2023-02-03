public String convert(String s, int numRows) {
    StringBuilder [] sb= new StringBuilder[numRows];
    for(int i=0;i<numRows;i++)
    {
        sb[i]= new StringBuilder();
    }
    char[] arr= s.toCharArray();
    int n= arr.length;
    int p=0;
    while(p<n)
    {
        for(int j=0;j<numRows && p<n;j++)
        {
            sb[j].append(arr[p++]);
        }
        for(int j=numRows-2;j>0 && p<n;j--)
        {
            sb[j].append(arr[p++]);
        }
    }
    StringBuilder res=sb[0];
    for(int i=1;i<numRows;i++)
    {
        res.append(sb[i].toString());
    }
    return res.toString();
}
}
