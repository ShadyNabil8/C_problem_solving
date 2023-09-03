int *acmTeam(int topic_count, char **topic, int *result_count)
{
    int *arr = (int *)calloc(2, sizeof(int));
    *result_count = 2;
    int attendees = topic_count;
    int topics = strlen(*topic);
    int topicsNum = 0;
    int teamsNum = 0;
    int temp = 0;
    for (int i = 0; i < attendees - 1; i++)
    {
        for (int j = i + 1; j < attendees; j++)
        {
            temp = 0;
            for (int k = 0; k < topics; k++)
            {
                temp += (topic[i][k] - 48) | (topic[j][k] - 48);
            }
            if (temp > topicsNum)
            {
                topicsNum = temp;
                teamsNum = 1;
            }
            else if (temp == topicsNum)
            {
                teamsNum++;
            }
            printf("%d\n", temp);
        }
    }
    arr[0] = topicsNum;
    arr[1] = teamsNum;
    return arr;
}