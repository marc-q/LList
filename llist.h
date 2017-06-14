#ifndef __LLIST_H__
#define __LLIST_H__

typedef struct LList
{
	void         *data;
	struct LList *next;
} LList;

LList * llist_alloc            (void);
LList * llist_last             (LList       *list);

void    llist_foreach          (LList       *list,
                                void         func (void *data,
                                                   void *udata),
                                void        *udata);

LList * llist_append           (LList       *list,
                                void        *data);
LList * llist_prepend          (LList       *list,
                                void        *data);

void    llist_free             (LList       *list);
void    llist_free_full        (LList       *list,
                                void         free_func (void *data));

void *  llist_find_custom      (LList       *list,
                                int          func (const void *data,
                                                   const void *udata),
                                const void  *udata);

#endif /* __LLIST_H__ */
