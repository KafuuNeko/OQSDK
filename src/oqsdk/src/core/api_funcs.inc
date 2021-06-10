
OQApi(bool, IsEnable);
OQApi(void, OutPutLog, const char *);
OQApi(void, SendMsg, const char *, int32_t, const char *, const char *, const char *, int32_t);
OQApi(void, SendMsgEx, const char *, int32_t, int32_t, const char *, const char *, const char *, int32_t);
OQApi(void, SendXML, const char *, int32_t, int32_t, const char *, const char *, const char *, int32_t);
OQApi(void, SendJSON, const char *, int32_t, int32_t, const char *, const char *, const char *);
OQApi(void, SendJsonEx, const char *, int32_t, int32_t, const char *, const char *, const char *, int32_t);

OQApi(const char *, UpVote, const char *, const char *);
OQApi(const char *, UpVoteEx, const char *, const char *);

OQApi(const char *, GetCookies, const char *);
OQApi(const char *, GetBlogPsKey, const char *);
OQApi(const char *, GetZonePsKey, const char *);
OQApi(const char *, GetGroupPsKey, const char *);
OQApi(const char *, GetClassRoomPsKey, const char *);
OQApi(const char *, GetBkn, const char *);
OQApi(const char *, GetBkn32, const char *);
OQApi(const char *, GetLongLdw, const char *);
OQApi(const char *, GetClientkey, const char *);
OQApi(const char *, GetLongClientkey, const char *);

OQApi(void, AdminInviteGroup, const char *, const char *, const char *);
OQApi(void, NoAdminInviteGroup, const char *, const char *, const char *);

OQApi(const char *, GetNick, const char *, const char *);
OQApi(const char *, GetGroupCard, const char *, const char *, const char *);
OQApi(int32_t, GetObjLevel, const char *, const char *);

