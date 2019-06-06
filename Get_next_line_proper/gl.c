char	*ft_gl(t_list *chunks, char **line)
{
	char	*tmp;

	
	if ((line_size = get_line_size(chunks)) != 0)
	{
		substr = ft_strsub_0((char*)chunks->content, 0 ,line_size);
		if (ft_strlen(substr))
			*out = ft_strjoin(*line, substr);
		ft_strdel(&substr);
	}
	return (out);
}
