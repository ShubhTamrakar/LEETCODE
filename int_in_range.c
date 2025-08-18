bool isCovered(int** ranges, int rangesSize, int* rangesColSize, int left, int right) {
    int c= 0;
    for(int i=left;i<=right;i++)
    {
        for(int j=0;j<rangesSize;j++)
        {
            if(ranges[j][0]<=i && i<=ranges[j][1])
            {c++;
            break;}
            
        }
    }
    return((right-left+1)==c)? true : false;
}
