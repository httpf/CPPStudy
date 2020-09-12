void push_back(string &&s)
{
    data->push_back(move(s));
}