# 📜 ft_mini_ls

## mandatory パート

`ls` コマンドに、オプションとして以下を標準適用させたものの実装。

- `-1` （要素ごとに改行）
- `-t` （作成日時順にソート）
- `-r` （逆順ソート）

## bonus パート

上記のものに加え、コマンドライン引数により以下のオプションに対応。

- `-a`  （隠しファイルも表示）
- `-A` （ `.` と `..` 以外の隠しファイルも表示）
- `-G` （ファイル種別の色付け表示）
- `-F` （ファイル識別子を表示）

## コンパイル & 実行

`make run`

# 📝学習メモ

> list_dir.c

```c
void				list_dir(void)
{
	DIR			*dir;
	t_file_data	*file_data_arr;
	const int	files_num = count_files();

	dir = opendir(CURRENT_DIR_PATH);
	if (dir == NULL)
		return (perror_with_error_flag());
	if (files_num == ERROR)
		return (perror_with_error_flag());
	file_data_arr = get_all_files_data(dir, files_num);
	closedir(dir);
	sort_files_by_time(file_data_arr, files_num);
	if (g_error_flag == true)
		return ;
	put_all_file_names(file_data_arr, files_num);
	SAFE_FREE(file_data_arr);
}
```

```c
#include <dirent.h>
DIR			*dir;

dir = opendir(CURRENT_DIR_PATH);
closedir(dir);
```

- `opendir()` 関数に、内容を見たいディレクトリのパスを渡し、オープンする。
- 失敗すると `NULL` が返る。
- 成功すると `DIR` 型のポインタが得られ、これを以降のディレクトリ読み出しに使う（ `fopen()` で得られる `FILE *` のようなもの）
- 使用を終える際は `closedir()` でクローズする。

```c
static int			count_files(void)
{
	DIR				*dir;
	size_t			files_num;
	struct dirent	*dir_ent;

	dir = opendir(CURRENT_DIR_PATH);
	if (dir == NULL)
		return (ERROR);
	files_num = 0;
	while ((dir_ent = readdir(dir)) != NULL)
	{
		if (dir_ent->d_name[0] == '.')
			continue ;
		files_num++;
	}
	closedir(dir);
	return (files_num);
}
```

```c
struct dirent	*dir_ent;

dir_ent = readdir(dir)
```

- `readdir()` : 引数のポインタによって参照されるディレクトリストリームの次のディレクトリエントリ(`dirent` 構造体)へのポインタを返す。
- `readdir()`に `DIR *` を渡すと、そのディレクトリ中のはじめの１つの内容を得られる。
- 呼び出すたびに次の内容が得られ、終わりに達すると `NULL` を返す
- `dirent` 構造体の主なメンバ

```c
__uint16_t  d_reclen　// このレコードの長さ
__uint8_t  d_namlen　// d_nameの文字列の長さ
char  d_name[]　// ディレクトリ名
```

```c
struct stat  dent_stat;

file_data_arr[index].tv_sec = dent_stat.st_mtimespec.tv_sec; // 作成秒
file_data_arr[index].tv_nsec = dent_stat.st_mtimespec.tv_nsec; // 作成ミリ秒
```

- `stat` 構造体のメンバーについて、詳細は[ソース１](https://www.c-lang.net/stat/index.html)や[ソース２](https://nxmnpg.lemoda.net/ja/2/stat)を参照。