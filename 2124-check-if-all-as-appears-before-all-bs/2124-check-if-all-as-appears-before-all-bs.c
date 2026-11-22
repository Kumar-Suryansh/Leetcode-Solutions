bool checkString(char* s) {
    int l =strlen(s);

    for(int i=0;i<l;i++)
    {
        if(s[i]=='b')
            if(s[i+1]=='a')
                return false;
    }
    return true;
    
}