
#include "ft_select.h"

t_file_type	get_file_type(char *name)
{
	struct stat		s;

	if (stat(name, &s) != 0)
		throw_error("Stat error");
	if ('.' == name[0])
		return (T_HIDDEN);
	else if (s.st_mode & S_IXUSR)
		return (T_BIN);
	else if (S_ISREG(s.st_mode))
		return (T_FILE);
	else if (S_ISDIR(s.st_mode))
		return (T_DIR);
	return (T_UNDEFINED);
}

static t_file		new_file(int index, char *name)
{
	t_file			res;

	res.index = index;
	res.file_type = get_file_type(name);
	res.visible = 1;
	res.checked = 0;
	res.name = name;
	return (res);
}

t_chain				*get_list(int ac, char **argv)
{
	t_chain			*chn;
	t_file			tmp_file;

	chn = 0;
	while (ac--)
	{
		tmp_file = new_file(ac, argv[ac]);
		ft_chnadd(&chn, ft_chnnew(&tmp_file, sizeof(tmp_file)));
	}
	return (chn);
}
