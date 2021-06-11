
OQApi(bool, IsEnable);
OQApi(void, OutPutLog, const char *);
OQApi(void, SendMsg, const char *, ono::MessageType, const char *, const char *, const char *, int32_t);
OQApi(void, SendMsgEx, const char *, int32_t, ono::MessageType, const char *, const char *, const char *, int32_t);
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
OQApi(const char *, GetFriendList, const char *);
OQApi(const char *, GetFriendList_B, const char *);
OQApi(const char *, GetQidianQQFriendsList, const char *);
OQApi(const char *, GetGroupAdmin, const char *, const char *);
OQApi(const char *, GetGroupList_A, const char *);
OQApi(const char *, GetGroupList, const char *);
OQApi(const char *, GetGroupList_B, const char *);
OQApi(const char *, GetGroupMemberList, const char *, const char *);
OQApi(const char *, GetGroupMemberList_B, const char *, const char *);
OQApi(const char *, GetGroupMemberList_C, const char *, const char *);

OQApi(bool, IsShutUp, const char *, const char *, const char *);
OQApi(void, ShutUP, const char *, const char *, const char *, int32_t);


OQApi(bool, JoinGroup, const char *, const char *, const char *);
OQApi(void, QuitGroup, const char *, const char *);

OQApi(const char *, UpLoadPic, const char *, int32_t, const char *, void *);
OQApi(const char *, GetPicLink, const char *, int32_t, const char *, const char *);

//OQApi(const char *, Tea加密, const char *, const char *);
//OQApi(const char *, Tea解密, const char *, const char *);

OQApi(const char *, SessionKey, const char *);

OQApi(const char *, GNTransGID, const char *);
OQApi(const char *, GIDTransGN, const char *);

OQApi(bool, PBGroupNotic, const char *, const char *, const char *, const char *);
OQApi(const char *, GetNotice, const char *, const char *);
OQApi(bool, ShakeWindow, const char *, const char *);
OQApi(bool, SetAnon, const char *, const char *, bool);
OQApi(bool, SetGroupCard, const char *, const char *, const char *, const char *);
OQApi(void, QuitDisGroup, const char *, const char *);
OQApi(const char *, CreateDisGroup, const char *, const char *);
OQApi(const char *, KickDisGroupMBR, const char *, const char *, const char *);
OQApi(const char *, InviteDisGroup, const char *, const char *, const char *);
OQApi(const char *, GetDisGroupList, const char *);
OQApi(const char *, GetDisGroupMemberList, const char *, const char *);
OQApi(void, SetDisGroupName, const char *, const char *, const char *);
OQApi(void, KickGroupMBR, const char *, const char *, const char *, bool);
OQApi(int64_t, GetObjVote, const char *, const char *);

OQApi(const char *, UpLoadVoice, const char *, int32_t, const char *, void *);
OQApi(const char *, GetVoiLink, const char *, const char *);
OQApi(int64_t, GetTimeStamp);

OQApi(const char *, SendPack, const char *, const char *);
OQApi(const char *, GetObjInfo, const char *, const char *);
OQApi(int32_t, GetGender, const char *, const char *);
OQApi(int32_t, GetQQAge, const char *, const char *);
OQApi(int32_t, GetAge, const char *, const char *);

OQApi(const char *, GetPerExp, const char *, const char *);
OQApi(const char *, GetSign, const char *, const char *);
OQApi(const char *, GetEmail, const char *, const char *);
OQApi(const char *, GetGroupName, const char *, const char *);


OQApi(const char *, GetVer);
OQApi(const char *, GetLog);
OQApi(const char *, GetQQList);
OQApi(const char *, GetOnLineList);
OQApi(const char *, GetOffLineList);
OQApi(void, DisabledPlugin);

OQApi(bool, AddQQ, const char *, const char *);
OQApi(const char *, DelQQ, const char *);
OQApi(void, LoginQQ, const char *);
OQApi(void, OffLineQQ, const char *);

OQApi(bool, IfFriend, const char *, const char *);

OQApi(void, SetRInf, const char *, int32_t, const char *);
OQApi(const char *, GetRInf, const char *);

OQApi(bool, DelFriend, const char *, const char *);
OQApi(bool, AddBkList, const char *, const char *);

OQApi(void, DelBkList, const char *, const char *);
OQApi(void, SetShieldedGroup, const char *, const char *, int32_t);

OQApi(bool, SendVoice, const char *, const char *, void *);

OQApi(const char *, SetAdmin, const char *, const char *, const char *, bool);

OQApi(void, PBHomeWork, const char *, const char *, const char *, const char *, const char *);

OQApi(const char *, WithdrawMsg, const char *, const char *, const char *, const char *);

OQApi(void, BeInput, const char *, const char *);
OQApi(const char *, GetQQAddMode, const char *, const char *);
OQApi(bool, IsOnline, const char *, const char *);
OQApi(int32_t, GetOnlineState, const char *, const char *);
OQApi(const char *, GetGroupMemberNum, const char *, const char *);
OQApi(bool, GetWpa, const char *, const char *);
OQApi(const char *, GetGroupAddMode, const char *, const char *);
OQApi(int32_t, GetGroupLv, const char *, const char *);

OQApi(void, SetFriendsRemark, const char *, const char *, const char *);
OQApi(const char *, GetFriendsRemark, const char *, const char *);

OQApi(bool, SignIn, const char *, const char *, const char *, const char *);
OQApi(const char *, TakeGift, const char *, const char *);
OQApi(const char *, CheckGift, const char *);
OQApi(int32_t, GiveGift, const char *, const char *, const char *, const char *);
OQApi(int32_t, GetGroupChatLv, const char *, const char *, const char *, const char *);
OQApi(int32_t, GetExpertDays, const char *, const char *);
OQApi(bool, InviteGroup_other, const char *, const char *, const char *, const char *);
OQApi(bool, GetShieldedState, const char *, int32_t);

OQApi(bool, DelFriend_A, const char *, const char *, int32_t);

OQApi(bool, Setcation_problem_B, const char *, const char *, const char *, const char *);

OQApi(bool, Setcation_problem_A, const char *, const char *, const char *, const char *);

OQApi(bool, HandleFriendEvent, const char *, const char *, int32_t, const char *);

OQApi(void, UpDate, const char *, const char *, const char *);

OQApi(const char *, GetQrcode);

OQApi(int32_t, CheckQrcode, const char *);

OQApi(const char *, GetCity, const char *, const char *);

OQApi(bool, SetGroupCation, const char *, const char *, int32_t, const char *, const char *);

OQApi(bool, IfGroupPrivate, const char *, const char *);

OQApi(void, Mark, const char *);

OQApi(void, DbgName, const char *);

OQApi(bool, UpHeadPic, const char *, void *);

OQApi(const char *, GetTenPayPsKey, const char *);

OQApi(const char *, GetJuBaoPsKey, const char *);

OQApi(const char *, GetOnlinFriend, const char *);

OQApi(bool, GetAnon, const char *, const char *);

OQApi(void, UpGroupFile, const char *, const char *, const char *);

OQApi(const char *, CreateGroup_A, const char *, const char *, const char *, const char *, const char *, const char *, const char *);

OQApi(bool, IsCreateGroup, const char *, const char *);

OQApi(const char *, GetReleaseNo);

OQApi(const char *, GetClientType);

OQApi(const char *, GetClientVer);

OQApi(bool, UpFriendFile, const char *, const char *, const char *);

OQApi(void, SetAge, const char *, const char *);

OQApi(bool, SetPerExp, const char *, const char *);

OQApi(const char *, OcrPic, const char *, const char *);
