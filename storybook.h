#ifndef STORYBOOK_H
#define STORYBOOK_H

#include "book.h"
#include <string>

class StoryBook : public book {
private:
    std::string Genre;
    std::string Type;
    bool IsIssueAllowed;

public:
    void createbook() override;
    void showbook() override;
    void modifybook() override;
};

#endif
