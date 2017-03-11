const int limit = 20000000;
bool visit[limit];
int prime[limit];
int primelen;
void getprim()
{
    primelen=0;
    visit[0]=visit[1]=true;
    for (int i = 2; i <= limit; ++i)
    {
        if (visit[i] == false)
        {
            prime[primelen++] = i;
        }
        for (int j = 0; ((j < primelen) && (i * prime[j] <limit));  ++j)
        {
            visit[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

