bool number[10][7] = {
    {true, true, true, true, true, true, false},
    {false, true, true, false, false, false, false},
    {true, true, false, true, true, false, true},
    {true, true, true, true, false, false, true},
    {false, true, true, false, false, true, true},
    {true, false, true, true, false, true, true},
    {true, false, true, true, true, true, true},
    {true, true, true, false, false, false, false},
    {true, true, true, true, true, true, true},
    {true, true, true, true, false, true, true}};
byte segments[7] = {2, 3, 4, 5, 6, 7, 8},
     common[4] = {10, 11, 12, 13},
     No[4];
byte c, i;

void display()
{
    for (i = 0; i < 4; i++)
    {
        digitalWrite(common[i], HIGH);
        for (c = 0; c < 7; c++)
            digitalWrite(segments[c], number[No[i]][c]);
        delay(5);
        digitalWrite(common[i], LOW);
    }
}

void count()
{
    No[3]++;
    if (No[3] > 9)
    {
        No[3] = 0;
        No[2]++;
        if (No[2] > 9)
        {
            No[2] = 0;
            No[1]++;
            if (No[1] > 9)
            {
                No[1] = 0;
                No[0]++;
                if (No[0] > 9)
                    No[0] = 0;
            }
        }
    }
}

void setup()
{
    for (c = 0; c < 7; c++)
        pinMode(segments[c], OUTPUT);
    for (c = 0; c < 4; c++)
        pinMode(common[c], OUTPUT);
}
void loop()
{
    display();
    if (millis() % 1000 == 0)
    {
        count();
    }
}