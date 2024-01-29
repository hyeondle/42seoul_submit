#ifndef DIRECTORYLISTING_HPP
#define DIRECTORYLISTING_HPP

#include <iostream>
#include <string>
#include <dirent.h>


class DirectoryListing {
private:
    DirectoryListing() {};
    ~DirectoryListing() {};

	std::string generateHTML(
			const std::vector<std::string>& directories,
			const std::vector<std::string>& files
	) {
		std::string html = "<html><head><meta charset=\"UTF-8\"></head><body><h1>Index</h1><hr><pre>";
		for (std::vector<std::string>::const_iterator it = directories.begin(); it != directories.end(); ++it) {
			html += "<a href=\"" + *it + "/\">" + *it + "/</a>\n";
		}
		for (std::vector<std::string>::const_iterator it = files.begin(); it != files.end(); ++it) {
			html += "<a href=\"" + *it + "\">" + *it + "</a>\n";
		}
		html += "</pre><hr></body></html>";
		return html;
	}
public:
    static DirectoryListing& getInstance() {
        static DirectoryListing instance;
        return instance;
    }

	std::map<int, std::string> run(const std::string& path) {
		DIR *dir;
		struct dirent *ent;
		std::vector<std::string> directories;
		std::vector<std::string> files;
		// ToDo: int값을 enum 활용하기
		// 1 : error number, Error Not found, is empty string, 2 : html string
		std::map<int, std::string> result;

		dir = opendir(path.c_str());

		if (dir != NULL) {
			while ((ent = readdir(dir)) != NULL) {
				if (ent->d_type == DT_DIR) {
					directories.push_back(ent->d_name);
				} else {
					files.push_back(ent->d_name);
				}
			}
			closedir (dir);
		} else {
			std::cout << "DirectoryListing : Could not open directory" << std::endl;
			result[1] = "Could not open directory";
			return result;
		}
		result[1] = "";
		result[2] = generateHTML(directories, files);
		return result;
	}
};

#endif // DIRECTORYLISTING_HPP
