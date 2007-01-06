/*	This file is a part of Freya.
		Freya is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	any later version.
		Freya is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.
		You should have received a copy of the GNU General Public License
	along with Freya; if not, write to the Free Software
	Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA */

#ifndef _PARTY_H_
#define _PARTY_H_

#include <stdarg.h>

struct party;
struct map_session_data;
struct block_list;

void do_init_party(void);
void do_final_party(void);
struct party *party_search(int party_id);
struct party* party_searchname(char *str);

void party_create(struct map_session_data *sd, char *name, short item, short item2);
int party_created(int account_id, int fail, int party_id, char *name);
int party_request_info(int party_id);
void party_invite(struct map_session_data *sd, int account_id);
int party_member_added(int party_id, int account_id, int flag);
void party_leave(struct map_session_data *sd);
void party_removemember(struct map_session_data *sd, int account_id, char *name);
void party_member_leaved(int party_id, int account_id, char *name);
void party_reply_invite(struct map_session_data *sd, int account_id, int flag);
int party_recv_noinfo(int party_id);
int party_recv_info(struct party *sp);
void party_recv_movemap(int party_id, int account_id, char *mapname, int online, int lv);
int party_broken(int party_id);
int party_optionchanged(int party_id, int account_id, unsigned short party_exp, unsigned char item, unsigned char flag);
int party_check_share_range(struct party *p, int level);
void party_changeoption(struct map_session_data *sd, unsigned short party_exp, unsigned short item);

void party_send_movemap(struct map_session_data *sd);
int party_send_logout(struct map_session_data *sd);

void party_send_message(struct map_session_data *sd, char *mes, int len);
int party_recv_message(int party_id, int account_id, char *mes, int len);

void party_check_conflict(struct map_session_data *sd);

int party_send_xy_clear(struct party *p);
int party_send_hp_check(struct block_list *bl, va_list ap);

void party_exp_share(struct party *p, short map_id, int base_exp, int job_exp, int zeny);

int party_sub_count(struct block_list *bl, va_list ap);
void party_foreachsamemap(int (*func)(struct block_list *, va_list), struct map_session_data *sd, int type, ...);

#endif // _PARTY_H_
