#include "Jobs.h"

Jobs::Jobs()
{
    head = tail = nullptr;
    string line;
    string job;
    int hours;
    int minutes;
    size_t errornumber = 0;
    ifstream infile;
    infile.open("jobs.txt");
    while(infile.is_open() && infile.good() && !infile.eof())
    {
        line = "";
        getline(infile, line);
        replace(line.begin(), line.end(), ';', ' ');
        istringstream ss(line);
        ss >> job >> hours >> minutes;
        if(line > "")
        {
            if((job.length() <= 8) && (hours <= 23 && hours >= 0) && (minutes <= 59 && minutes >= 0))
            {
                Record temp(job, hours, minutes);
                if(tail != nullptr)
                {
                    tail -> next = new Node(temp);
                    tail = tail -> next;
                }
                else
                {
                    head = new Node(temp);
                    if(tail == nullptr)
                        tail = head;
                }
            }
            else
            {
                    ++errornumber;
                    cout << "Error" << '\n';
                    cout << "-------" << '\n';
                    cout << job << " " << hours << " " << minutes << '\n';
                    cout << endl;
            }
        }
    }
    infile.close();
    cout << errornumber << " record(s) are Invalid" << '\n';
    change(head);
}

Jobs::~Jobs()
{
    if(!isEmpty())
    {
        Node* current;
        current = head;
        while(current != nullptr)
        {
            Node* nxtNode = current -> next;
            delete current;
            current = nxtNode;
        }

        head = nullptr;
        cout << "Destructor Called! The List has been freed" << '\n';
    }
    /*else
    {
        cout << "Destructor Called! The List is empty from the start" << '\n';
    }*/

}

bool Jobs::isEmpty()
{
    return head == nullptr;
}

void Jobs::_swap(Node* lhs, Node* rhs)
{
    Record p;
    p = lhs -> info;
    lhs -> info = rhs -> info;
    rhs -> info = p;
}

Node Jobs::change(Node* head)
{
    vector<Record> data;
    Node* p = head;
    while(p)
    {
        data.push_back(p->info);
        p = p -> next;
    }
    sort(data.begin(), data.end(), [](const Record& lhs, const Record& rhs){return((lhs.getHours() < rhs.getHours()) || (((lhs.getHours() == rhs.getHours())) && (lhs.getMinutes() <= rhs.getMinutes())));});
    p = head;
    for(const auto& elem: data)
    {
        p -> info = elem;
        p = p -> next;
    }

    return *head;
}

/*void Jobs::Sort(Node* head)
{
    Node* beg = nullptr;
    Node* tmp = nullptr;
    beg = head;

    while(beg != nullptr)
    {
        tmp = beg;
        while(tmp -> next != nullptr)
        {
            if((tmp -> info.getHours() > tmp -> next -> info.getHours()) || ((tmp -> info.getHours() == tmp -> next -> info.getHours()) && (tmp -> info.getMinutes() >= tmp -> next -> info.getMinutes())))
            {
                _swap(tmp, tmp -> next);
            }
            tmp = tmp -> next;
        }
        beg = beg -> next;
    }

}
*/

void Jobs::runServer()
{
    Node* tmp;
    while(true)
    {
        time_t t = time(0);
        tm* now = localtime(&t);
        time_t hours = now->tm_hour;
        time_t minutes = now->tm_min;
        if(((head->info.getHours() == hours) && (head->info.getMinutes() <= minutes)) || (head->info.getHours() < hours))
        {

            tmp = head;
            head = head -> next;
            cout << tmp->info.getJob() << " " << tmp->info.getHours() << " " << tmp->info.getMinutes() << '\n';
            delete tmp;

        }
        else
        {
            Node* current = head;
            while(current -> next != nullptr)
            {
                if(((current->next->info.getHours() == hours) && (current->next->info.getMinutes() <= minutes)) || (current->next->info.getHours() < hours))
                    {
                        tmp = current -> next;
                        current -> next = current -> next -> next;
                        cout << tmp->info.getJob() << " " << tmp->info.getHours() << " " << tmp->info.getMinutes() << '\n';
                        delete tmp;
                        break;
                    }
                    else
                    {
                        current = current -> next;
                    }
            }
        }
        if(isEmpty())
        {
            break;
        }

    }


}

void Jobs::print()
{
    Node* current;
    current = head;
    while(current != nullptr)
    {
        cout << current->info.getJob() << " " << current->info.getHours() << " " << current->info.getMinutes() << '\n';
        current = current -> next;
    }
}
