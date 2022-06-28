bool ac = false;
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
byte segments[7] = {2, 3, 4, 5, 6, 7, 8};
byte c, f;

void display(byte i)
{
    for (c = 0; c < 7; c++)
        digitalWrite(segments[c], number[i][c]);
}

void setup()
{
    for (c = 0; c < 7; c++)
        pinMode(segments[c], OUTPUT);
    if (ac)
    {
        for (c = 0; c < 10; c++)
            for (f = 0; f < 7; f++)
                number [c][f] = !number[c][f];
        f = 0;
    }
}

void loop()
{
    display(f);
    delay(600);
    f++;
    if (f > 9)
        f = 0;
}