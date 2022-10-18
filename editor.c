#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char ch;
  struct Node *prev;
  struct Node *next;
} Node;

Node *alloc_new_node(char ch);
void init_list(Node **head, Node **tail, Node **curr);
void init_str(Node *curr);
void cmd_L(Node *head, Node **curr);
void cmd_D(Node *tail, Node **curr);
void cmd_B(Node *head, Node *curr);
void cmd_P(Node *curr, char ch);
void print_str(Node *head, Node *tail);
void free_list(Node *head);

int main(void)
{
  int M;
  char cmd, ch;
  Node *head, *tail, *curr;
  init_list(&head, &tail, &curr);
  init_str(curr);

  scanf("%d", &M);
  for(int i = 0; i < M; i++)
  {
    scanf(" %c", &cmd);
    switch(cmd)
    {
      case 'L': cmd_L(head, &curr); break;
      case 'D': cmd_D(tail, &curr); break;
      case 'B': cmd_B(head, curr);  break;
      case 'P': scanf(" %c", &ch);
                cmd_P(curr, ch);
                break;
    }
  }

  print_str(head, tail);
  free_list(head);

  return 0;
}

Node *alloc_new_node(char ch)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->ch = ch;
  new_node->prev = NULL;
  new_node->next = NULL;

  return new_node;
}

void init_list(Node **head, Node **tail, Node **curr)
{
  *head = alloc_new_node(' ');
  *tail = alloc_new_node(' ');
  (*head)->next = *tail;
  (*tail)->prev = *head;
  *curr = *tail;
}

void init_str(Node *curr)
{
  char ch;

  while(1)
  {
    scanf("%c", &ch);
    if(ch == '\n')
      return;
    cmd_P(curr, ch);
  }
}

void cmd_L(Node *head, Node **curr)
{
  if((*curr)->prev == head)
    return;
  *curr = (*curr)->prev;
}

void cmd_D(Node *tail, Node **curr)
{
  if(*curr == tail)
    return;
  *curr = (*curr)->next;
}

void cmd_B(Node *head, Node *curr)
{
  if(curr->prev == head)
    return;
  Node *rm_node = curr->prev;
  rm_node->prev->next = rm_node->next;
  rm_node->next->prev = rm_node->prev;
  free(rm_node);
}

void cmd_P(Node *curr, char ch)
{
  Node *new_node = alloc_new_node(ch);
  new_node->prev = curr->prev;
  new_node->next = curr;
  curr->prev->next = new_node;
  curr->prev = new_node;
}

void print_str(Node *head, Node *tail)
{
  for(head = head->next; head != tail; head = head->next)
    printf("%c", head->ch);
  printf("\n");
}

void free_list(Node *head)
{
  Node *rm_node;
  while(head != NULL)
  {
    rm_node = head;
    head = head->next;
    free(rm_node);
  }
}
