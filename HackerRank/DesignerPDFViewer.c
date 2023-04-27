int designerPdfViewer(int h_count, int* h, char* word) {
    /*1-Find the langth of the word*/
    unsigned int length = 0;
    while (word[length] != '\0')
    {
        length++;
    }
    
    /*2- find the max height in the word*/
    int maxHeight = 0;
    for(int i = 0 ; i < h_count ; i++)
    {
        /* word[i] - 'a' + 1 is the ordr of the char in the English alphabet (zero-based)*/
        maxHeight = ((h[word[i] - 'a']) > maxHeight) ? (h[word[i] - 'a']) : maxHeight;
    }
    return maxHeight*length;

}