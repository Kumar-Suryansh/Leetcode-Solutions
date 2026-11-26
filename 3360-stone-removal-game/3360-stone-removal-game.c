bool canAliceWin(int n) {
    int x=n-10,i=1;
    if(x<0)
        return false;

        while(true)
        {
            int y=x-(10-i);
            if(y<0)
                return i%2==1;
             x=y;
             i++;
        }
    }
    
