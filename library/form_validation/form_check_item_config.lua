form_check_item_config.change_nickname = {
	["field"] = "nickname",
	["label"] = "用户昵称",
	["rules"] = "required|min_length[1]|max_length[30]|is_unique[user.nickname]"
}
