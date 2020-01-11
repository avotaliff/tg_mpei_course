//https://leetcode.com/problems/design-twitter/
//супер душное решение задачки но зато самое очевидно, как и учил Антошка с курсеры
//чет эта задача сильно напоминает курсеру
class Twitter {
public:
    map<int, vector <int>> user_follows;
    vector<pair<int, int>> all;

    /*Конструктор \U0001f60e*/
    Twitter() {}
    
    /*Новый твит \U0001f60e */
    
    void postTweet(int userId, int tweetId) {
        all.push_back(make_pair(userId, tweetId));
    }

    /* Получить 10 последних ид твитов в ленте новостей пользователя. Каждый элемент в новостной ленте должен публиковаться пользователем, за которыми следил пользователь, или самим пользователем. Твиты должны быть просмотрены от самых последних до самых последних. \U0001f60e */
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int est = 0;
        for (auto& twit : all){
//просматриваем все твиты и добавляем в результат, если это твит пользователя или кого-то, за кем он следует \U0001f60e
            est = count(user_follows[userId].begin(),user_follows[userId].end(), twit.first);
    if (twit.first == userId || est>0){
                res.push_back(twit.second);
            }
        }
        
        std::reverse(res.begin(),res.end());
        if (res.size() > 10)
            res.resize(10);
        return res;
    }
    
    /* ФОЛОВ ФОЛОВЕРД ФОЛОФЕЕРД ПАЗПХАЗПАХЗ \U0001f60e*/
    void follow(int followerId, int followeeId) {
        user_follows[followerId].push_back(followeeId);
    }
    
    /* ФОЛОВ УНФОЛОВ ФОЛОЫЕЕД ПАХЗПХЗПА \U0001f60e*/
    void unfollow(int followerId, int followeeId) {
        if (user_follows.find(followerId) != user_follows.end())
        { 
            user_follows[followerId].erase(remove(user_follows[followerId].begin(),
                                                  user_follows[followerId].end(),
                                                    followeeId),
                                           user_follows[followerId].end());
        }
    }
};

// НУ И ДУШНАЯ ЗАДАЧКА 
