
            if(head==nullptr)
            {
                head=tail=newNode;
                tail->next=head;
            }
            else
            {
                tail->next=newNode;
                tail=newNode;
                tail->next=head;