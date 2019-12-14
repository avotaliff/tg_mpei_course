//https://leetcode.com/problems/design-twitter/
//супер душное решение задачки но зато самое очевидно, как и учил Антошка с курсеры
//чет эта задача сильно напоминает курсеру
class Twitter {
public:
    map<int, map<int, int>> user_follows;
    vector<pair<int, int>> all;

    /*Конструктор 😎*/
    Twitter() {}
    
    /*Новый твит 😎 */
    
    void postTweet(int userId, int tweetId) {
        all.push_back(make_pair(userId, tweetId));
    }

    /* Получить 10 последних идентификаторов твитов в ленте новостей пользователя. Каждый элемент в новостной ленте должен публиковаться пользователями, за которыми следил пользователь, или самой пользователем. Твиты должны быть заказаны от самых последних до самых последних. 😎 */
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        for (auto& twit : all){
//просматриваем все твиты и добавляем в результат, если это твит пользователя или кого-то, за кем он следует 😎
    if (twit.first == userId ||                                                                 
        user_follows[userId].find(twit.first) != user_follows[userId].end()){
                res.push_back(twit.second);
            }
        }
        
        std::reverse(res.begin(),res.end());
        if (res.size() > 10)
            res.resize(10);
        return res;
    }
    
    /* ФОЛОВ ФОЛОВЕРД ФОЛОФЕЕРД ПАЗПХАЗПАХЗ 😎*/
    void follow(int followerId, int followeeId) {
        user_follows[followerId][followeeId] = 1;
    }
    
    /* ФОЛОВ УНФОЛОВ ФОЛОЫЕЕД ПАХЗПХЗПА 😎*/
    void unfollow(int followerId, int followeeId) {
        if (user_follows.find(followerId) != user_follows.end())
        {
            user_follows[followerId].erase(followeeId);
        }
    }
};

// НУ И ДУШНАЯ ЗАДАЧКА 
