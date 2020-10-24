
void Message::move_to_folders(Message *m)
{
    folders = std::move(m->folders);
    for(auto f: folders)
    {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

Message::Message(Message &&m): contents(std::move(m.contents))
{
    move_folders(&m);
}

Message& Message::operator=(Message &&rhs)
{
    if(this != &rhs)
    {
        move_from_folders();
        contents = std::move(rhs.contents);
        move_folders(&rhs);
    }
    return *this;
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}