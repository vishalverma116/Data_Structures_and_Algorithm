// reference link : http://www.cplusplus.com/reference/

//#include<bits/stdc++.h>
#include<iostream>
#include<functional>
#include<iterator>
#include<algorithm>
#include<array>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<unordered_set>
#include<list>
#include<forward_list>
#include<map>
#include<unordered_map>




using namespace std;

void Operators(){
    plus<int> int_add;
    plus<string> str_add;
    cout<<"3 + 5 = "<<int_add(3,5);
    cout<<"a + b = "<<str_add("a","b");

    plus<size_t> u_adder;
    cout<<"4 + 4 = "<<u_adder(4,4)<<"\n";

    
    string a = "vis";
    string b = "hal";
    cout<<"'vis' + 'hal' = "<<str_add(a,b)<<"\n";

    minus<int> int_minus;
    cout<<"4 - 3 = "<<int_minus(4,3)<<"\n";

    multiplies<int> mul_int;
    cout<<"4 * 3 = "<<mul_int(4,3)<<"\n";

    divides<int> div_int;
    cout<<"12 / 3 = "<<div_int(12,3)<<"\n";

    modulus<int> mod_int;
    cout<<"13 % 3 = "<<mod_int(13,3)<<"\n";

    negate<int> neg_int;
    cout<<"negate of 3 = "<<neg_int(3)<<"\n";

    //negation<int> negation_int;
    //cout<<"negation of 3 = "<<negation_int(3,3)<<"\n";

    // these all functions can be used on arrays as well with other functions
    // example -- 
    int ar[] = {1,2,3,4,5};
    transform(ar,ar+5,ar,negate<int>());
    for(int i=0;i<5;i++)
        cout<<ar[i]<<" ";
    cout<<"\n";
    
    // ------ arithmetic operators -------
    //plus<type> // calls the binary operator +;
    //minus<type> // calls the binary operator -;
    //multiplies<type> // calls the binary operator *;
    //divides<type> // calls operator /;
    //modulus<type> // calls operator %;
    //negate<type> //calls the unary operator-. This arithmetic function object is a unary function object as it expects one argument.


    // ------ Reational operators --------
    //equal_to<type> // calls operator==;
    //not_equal_to<type> // calls operator!=;
    //greater<type> //  calls operator>;
    //greater_equal<type> //  calls operator>=;
    //less<type> // this object's member operator() calls operator<;
    //less_equal<type> // calls operator<=.


    // ------ Logical operators --------
    //logical_and<type> // calls operator&&;
    //logical_or<type> // calls operator||;
    //logical_not<type> // calls operator!.


}

void iterators(){
    // comes under <iterator> headerfile

    /*
        back_inserter: calls the container's push_back member to add new elements at the end of the container. 
        E.g., to copy all elements of source in reversed order to the back of destination, using the copy generic algorithm:
        copy(source.rbegin(), source.rend(), back_inserter(destination));
        
        front_inserter calls the container's push_front member, adding new elements at the beginning of the container. 
        E.g., to copy all elements of source to the front of the destination container (thereby also reversing the order of the elements):
        copy(source.begin(), source.end(), front_inserter(destination));
    
        inserter calls the container's insert member adding new elements starting at a specified starting point. 
        E.g., to copy all elements of source to the destination container, starting at the beginning of destination, shifting up existing elements to beyond the newly inserted elements:
        copy(source.begin(), source.end(), inserter(destination, destination.begin()));
    */

    //cin.unsetf(ios::skipws);
    //copy(istream_iterator<char>(cin), istream_iterator<char>(), ostream_iterator<char>(cout));

    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    vector<int>::iterator it = v.begin();  // or
    // auto it = v.begin()
    for( ;it!= v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<"\n";

}

void array_demo(){
    array<int, 5> a = {12,34,56,78,90};
    //for(int i=0;i<5;i++)  cin>>a.at(i);
    
    // variation of printing
    for(int i=0;i<5;i++)
        cout<<a[i]<<" "; // or // cout<<a.at(i)<<" ";
    cout<<"\n";

    for(auto i = a.begin();i!=a.end();++i) // cbegin and cend are also there
        cout<<*i<<" ";
    cout<<"\n";

    for(int& x : a){
        cout<<x<<" ";
    }
    cout<<"\n";

    // printing reverse
    for(auto i = a.crbegin();i < a.crend() ;++i)  // contant_reverse_iterator // rbegin and rend are also there
        cout<<*i<<" ";
    cout<<"\n";

    cout<<a.empty()<<"\n";

    cout<<"front of array = "<<a.front()<<"\n";
    cout<<"back of array = "<<a.back()<<"\n";

    cout<<"size of array a = "<<a.size()<<"\n";
    cout<<"max size of array a = "<<a.max_size()<<"\n";
    
    array<int,5> b;
    b.fill(5);
    for( auto x : b) cout<<x<<" ";
    cout<<"\n";

    a.swap(b);
    for(int& x: a) cout<<x<<" ";
    cout<<"\n";
    for(int&x : b) cout<<x<<" ";
    cout<<"\n";

    cout<<"second element of array b = "<<get<1>(b)<<"\n";

    //sorting an array
    a = {34,78,12,90,56};
    sort(a.begin(),a.end());
    cout<<"sorted array = ";
    for(int& x: a) cout<<x<<" ";
    cout<<"\n";

    // binary search on array
    cout<<binary_search(a.begin(),a.end(), 56)<<"\n";
    cout<<binary_search(a.begin(),a.end(), 100)<<"\n";

    array<int, 5>::iterator it1,it2,max,min;
    it1 = lower_bound(a.begin(),a.end(),56); // >=
    it2 = upper_bound(a.begin(),a.end(),78); // >
    cout<<*it1<<" "<<*(it2-1)<<"\n";

    cout<<"max element of array a = "<<*max_element(a.begin(),a.end())<<"\n";
    cout<<"min element of array a = "<<*min_element(a.begin(),a.end())<<"\n";


    
}

void vector_demo(){
    // library = <vector>

    //vector::assign    // assign a value to given number of locations
    //vector::at        // to go anyindex v.at(5) // going on 5th location
    //vector::begin     // points to 0th addres of vector
    //vector::end       // points to end of vector
    //vector::capacity  // gives you the capacity of vector
    //vector::cbegin    // constant_iterator
    //vector::cend
    //vector::rbegin
    //vector::rend
    //vector::crbegin
    //vector::crend
    //vector::clear     // clears the vector
    //vector::data      
    //vector::empty     // checks if vector is empty
    //vector::pop_back
    //vector::push_back
    //vector::emplace   // insert element at any position
    //vector::emplace_back
    //vector::erase
    //vector::front
    //vector::back
    //vector::get_allocator //Returns a copy of the allocator object associated with the vector.
    //vector::insert
    //vector::max_size
    //vector::operator '='
    //vector::operator '[]'
    //vector::reserve       //Requests that the vector capacity be at least enough to contain n elements.
    //vector::resize        //Resizes the container so that it contains n elements.
    //vector::shrink_to_fit //Requests the container to reduce its capacity to fit its size.
    //vector::size
    //vector::swap
    //vector::sort
    //vector::search
    //vector::binary_search
    //vector::upper_bound
    //vector::lower_bound
    //vector::max_element
    //vector::min_element
    //...


    vector<int> v;
    v.assign(7,100); // assigns value to a vector // first 7 gets 100 assigned to them
    v.push_back(19);
    v.push_back(45);
    //cout<<v.data()<<"\n";
    for(int& x: v) cout<<x<<" ";
    cout<<"\n";
    v.pop_back();

    for(int& x: v) cout<<x<<" ";
    cout<<"\n";

    v.clear();
    cout<<v.empty()<<"\n";

    v.emplace(v.begin(),12); // insert element at position
    v.emplace(v.end(), 45);
    v.emplace(v.end()-1,46);
    v.emplace(v.begin()+2,78);
    v.emplace_back(3); // similar as push_back

    for(int& x: v) cout<<x<<" ";
    cout<<"\n";

    v.erase(v.begin()+3); // erasing 4th element of vector
    for(int& x: v) cout<<x<<" ";
    cout<<"\n";

    v.erase(v.begin(),v.begin()+2); // erasing first two elements
    for(int& x: v) cout<<x<<" ";
    cout<<"\n";

    //insert
    v.insert(v.begin(),2,300);
    int a[] = {10,20,30};
    v.insert(v.begin(),a,a+3);
    v.insert(v.begin()+5,a,a+3);
    for(auto x: v) cout<<x<<" ";
    cout<<"\n";
    cout<<"size of vector v: "<<v.size()<<"\n";
    cout<<"Capacitty of vector v: "<<v.capacity()<<"\n";
    cout<<"maxsize of vector v: "<<v.max_size()<<"\n";



}

void pair_demo(){
    pair<int,int> p;
    p = make_pair(2,4);
    p = make_pair(1,5);
    cout<<p.first<<" "<<p.second<<"\n";
}

void tuple_demo(){
    tuple<int,int,int> tup (10,20,30);
    cout<<get<0>(tup);
}

void stack_demo(){
    // library = <stack>

    //stack::emplace
    //stack::empty
    //stack::push
    //stack::pop
    //stack::size
    //stack::swap
    //stack::top
    //stack::back
    stack<int> stk;
    stk.push(2);
    stk.push(5);
    stk.emplace(78);
    stk.emplace(45);
    stk.push(34);
    cout<<"Top element of my stack = "<<stk.top()<<"\n";
    stk.pop();
    cout<<"Top element of my stack after pop = "<<stk.top()<<"\n";
    cout<<"size of my stack = "<<stk.size()<<"\n";
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<"\n";
    
}

void queue_demo(){
    // library = <queue>

    //queue::push
    //queue::pop
    //queue::back
    //queue::front
    //queue::emplace
    //queue::empty
    //queue::size
    //queue::swap

    queue<int> q;
    q.push(12);
    q.push(24);
    q.emplace(45);
    q.emplace(67);
    cout<<"front of queue = "<<q.front()<<"\n";
    cout<<"back of queue = "<<q.back()<<"\n";
    cout<<"size of queue = "<<q.size()<<"\n";
    q.pop();
    cout<<"front after pop = "<<q.front()<<"\n";
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<"\n";

}

void priority_queue_demo(){
    //library = <queue>

    //priority_queue::push
    //priority_queue::pop
    //priority_queue::emplace
    //priority_queue::empty
    //priority_queue::size
    //priority_queue::top
    //priority_queue::swap

    priority_queue<int> pq;
    pq.push(23);
    pq.push(100);
    pq.push(24);
    pq.push(3);
    pq.emplace(40);
    cout<<"top of priority queue = "<<pq.top()<<"\n";
    cout<<"size of priority queue = "<<pq.size()<<"\n";
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<"\n";
}

void deque_demo(){
    // library - <deque>

    //deque::assign
    //deque::at
    //deque::back
    //deque::front
    //deque::begin, cbegin, rbegin crbegin
    //deque::end, cend, rend, crend
    //deque::clear
    //deque::push_front
    //deque::pop_front
    //deque::push_back
    //deque::pop_back
    //deque::emplace
    //deque::emplace_back
    //deque::empty
    //deque::end
    //deque::erase
    //deque::insert
    //deque::get_allocator
    //deque::max_size
    //deque::operator '='
    //deque::operator '[]'
    //deque::resize
    //deque::shrink_to_fit
    //deque::size
    //deque::swap
    deque<int> dq;
    dq.push_front(20);
    dq.push_front(67);
    dq.push_back(400);
    dq.push_back(45);
    dq.emplace(dq.end(),1000);
    dq.emplace_front(345);
    dq.emplace_back(2000);
    cout<<"front of deque = "<<dq.front()<<"\n";
    cout<<"back of deque = "<<dq.back()<<"\n";
    for(auto x:dq) cout<<x<<" ";
    cout<<"\n";
    dq.pop_back();
    dq.pop_front();
    for(auto x:dq) cout<<x<<" ";
    cout<<"\n";

}

bool less_than_thirty(const int& value){ return (value<30); }

void list_demo(){
    // library = <list>
    // these are implemented as doubly linked list

    //list::assign
    //list::back
    //list::front
    //list::begin, cbegin, rbegin, crbegin
    //list::end, cend, rend, crend
    //list::emplace
    //list::emplace_back
    //list::emplace_front
    //list::empty
    //list::end
    //list::erase
    //list::get_allocator
    //list::insert
    //list::max_size
    //list::merge
    //list::operator "="
    //list::pop_back
    //list::pop_front
    //list::push_back
    //list::push_front
    //list::remove
    //list::remove_if
    //list::resize
    //list::reverse
    //list::size
    //list::sort
    //list::splice
    //list::swap
    //list::unique

    list<int> dl;
    dl.push_back(400);
    dl.push_front(3000);
    dl.emplace_front(356);
    dl.emplace_back(456);
    for(auto x:dl) cout<<x<<" ";
    cout<<"\n";
    list<int>::iterator it;
    it = dl.begin();
    dl.erase(++it);
    for(auto x:dl) cout<<x<<" ";
    cout<<"\n";

    it = dl.begin();
    ++(++it);
    dl.insert(it,1030);

    list<int> dl1;
    dl1.push_back(34);
    dl1.push_back(12);
    dl1.push_back(25);

    dl.sort();
    dl1.sort();

    dl.merge(dl1);
    for(auto x:dl) cout<<x<<" ";
    cout<<"\n";

    cout<<"is dl1 empty = "<<dl1.empty()<<"\n";

    dl.remove(12);
    for(auto x:dl) cout<<x<<" ";
    cout<<"\n";

    dl.remove_if(less_than_thirty);
    for(auto x:dl) cout<<x<<" ";
    cout<<"\n";

    dl.reverse();
    for(auto x:dl) cout<<x<<" ";
    cout<<"\n";

    dl.push_back(34);
    dl.push_back(1030);
    for(auto x:dl) cout<<x<<" ";
    cout<<"\n";

    dl.unique();
    for(auto x:dl) cout<<x<<" ";
    cout<<"\n";

    dl1.splice(dl1.begin(),dl,it);
    for(auto x:dl1) cout<<x<<" ";
    cout<<"\n";
    for(auto x:dl) cout<<x<<" ";
    cout<<"\n";



    // reference link - http://www.cplusplus.com/reference/list/list/splice/
}

void forward_list_demo(){
    //library = <forward_list
    // singly linked list

    //forward_list::assign
    //forward_list::before_begin //Returns an iterator pointing to the position before the first element in the container.
    //forward_list::begin , cbegin
    //forward_list::cbefore_begin
    //forward_list::end, cend
    //forward_list::clear
    //forward_list::emplace_after
    //forward_list::emplace_front
    //forward_list::empty
    //forward_list::erase_after
    //forward_list::front
    //forward_list::get_allocator
    //forward_list::insert_after
    //forward_list::max_size
    //forward_list::merge
    //forward_list::operator=
    //forward_list::pop_front
    //forward_list::push_front
    //forward_list::remove
    //forward_list::remove_if
    //forward_list::resize
    //forward_list::reverse
    //forward_list::sort
    //forward_list::splice_after
    //forward_list::swap
    //forward_list::unique

    forward_list<int> fll;
    fll.push_front(34);
    fll.emplace_front(23);
    fll.emplace_after(fll.begin(),12);
    fll.insert_after(fll.before_begin(),1);
    for(auto x:fll ) cout<<x<<" ";
    cout<<"\n";

    forward_list<int>::iterator it = fll.begin();
    fll.erase_after(++it);
    for(auto x:fll ) cout<<x<<" ";
    cout<<"\n";
    // rest all function work same as list   
}

void set_demo(){
    // library - <set>
    // Sets are implemented as Balanced Binary Search Trees

    //set:: begin, cbegin, rbegin, crbegin
    //set:: end, cend, rend, crend
    //set:: clear
    //set:: count
    //set:: emplace
    //set:: emplace_hint
    //set:: empty
    //set:: end
    //set:: erase
    //set:: equal_range // Returns the bounds of a range that includes all the elements in the container that are equivalent to val.
    //set:: find
    //set::get_allocator
    //set::insert
    //set::key_comp
    //set::lower_bound
    //set::max_size
    //set::operator '='
    //set::size
    //set::swap
    //set::upper_bound
    //set::value_comp

    set<int> s;
    s.insert(34);
    s.insert(23);
    s.insert(56);
    s.insert(4);
    s.insert(4);
    for(auto x:s) cout<<x << " ";
    cout<<"\n"; 
    cout<<s.count(4)<<"\n";
    s.emplace_hint(s.cend(),4);
    s.emplace_hint(s.cend(),5);
    for(auto x:s) cout<<x << " "; cout<<"\n";

}

void multiset_demo(){
    //library = <set>
    // same as only difference is, it doesn't keep unique value; it can have multiple same values but sorted.

    /*
    multiset::begin, cbegin, rbegin, crbegin
    multiset::end, cend, rend, crend
    multiset::clear
    multiset::count
    multiset::emplace, emplace_hint
    multiset::empty
    multiset::equal_range
    multiset::erase
    multiset::find
    multiset::get_allocator
    multiset::insert
    multiset::key_comp, value_comp
    multiset::upper_bound, lower_bound
    multiset::max_size, size
    multiset::operator=
    multiset::swap
    */

   multiset<int> ms;
   ms.insert(45);
   ms.insert(12);
   ms.insert(23);
   ms.insert(12);
   ms.insert(45);
   for(auto x: ms) cout<<x<<" "; cout<<"\n";
   // rest working is same as set
}

void unordered_set_demo(){
    // library = <unordered_set>
    // same as <set> only difference is it doesn't keep the elements sorted but unique
    //Hash-table used to store elements

    /*
    unordered_set::begin, cbegin
    unordered_set::end, cend
    unordered_set::bucket
    unordered_set::bucket_count
    unordered_set::bucket_size
    unordered_set::clear
    unordered_set::count
    unordered_set::emplace, emplace_hint
    unordered_set::empty
    unordered_set::equal_range
    unordered_set::erase
    unordered_set::find
    unordered_set::get_allocator
    unordered_set::hash_function
    unordered_set::insert
    unordered_set::key_eq
    unordered_set::load_factor // = size/bucket_count
    unordered_set::max_bucket_count
    unordered_set::max_load_factor
    unordered_set::max_size
    unordered_set::operator=
    unordered_set::rehash
    unordered_set::reserve
    unordered_set::size
    unordered_set::swap
    */
    unordered_set<int> us;
    us.insert(45);
    us.insert(12);
    us.insert(23);
    us.insert(12);
    us.insert(45);
    for(auto x: us) cout<<x<<" "; cout<<"\n";

    for(auto x:us) cout<<x<<" is in bucket "<<us.bucket(x)<<"\n";
    cout<<"My unordered set has "<<us.bucket_count()<<"\n";
    for(unsigned x = 0;x<us.bucket_count();++x) cout<<"size of bucket "<<x<<" is ="<<us.bucket_size(x)<<"\n";
    cout << "max_size = " << us.max_size() << endl;
    cout << "max_bucket_count = " << us.max_bucket_count() << endl;
    cout << "max_load_factor = " << us.max_load_factor() << endl;

}

void unordered_multiset_demo(){
    // library = <unordered_set>

    //Unordered multisets are containers that store elements in no particular order,
    // allowing fast retrieval of individual elements based on their value, 
    //much like unordered_set containers, but allowing different elements to have equivalent values.

    /*    
    unordered_multiset::begin, cbegin
    unordered_multiset::end, cend
    unordered_multiset::bucket
    unordered_multiset::bucket_count
    unordered_multiset::bucket_size
    unordered_multiset::clear
    unordered_multiset::count
    unordered_multiset::emplace
    unordered_multiset::emplace_hint
    unordered_multiset::empty
    unordered_multiset::equal_range
    unordered_multiset::erase
    unordered_multiset::find
    unordered_multiset::get_allocator
    unordered_multiset::hash_function
    unordered_multiset::insert
    unordered_multiset::key_eq
    unordered_multiset::load_factor
    unordered_multiset::max_bucket_count
    unordered_multiset::max_load_factor
    unordered_multiset::max_size
    unordered_multiset::operator=
    unordered_multiset::rehash
    unordered_multiset::reserve
    unordered_multiset::size
    unordered_multiset::swap
    */

    unordered_multiset<int> ums;
    ums.insert(45);
    ums.insert(12);
    ums.insert(23);
    ums.insert(12);
    ums.insert(45);
    for(auto x:ums) cout<<x<<" "; cout<<"\n";

    // rest is same as <unordered_set>
}

void map_demo(){
    //library = <map>

    /*
    Maps are associative containers that store elements formed by a combination of a key value and 
    a mapped value, following a specific order.
    In a map, the key values are generally used to sort and uniquely identify the elements, 
    while the mapped values store the content associated to this key. The types of key and 
    mapped value may differ, and are grouped together in member type value_type, 
    which is a pair type combining both
    */

    /*    
    map::at
    map::begin, cbegin, rbegin, crbegin
    map::end, cend, rend, crend
    map::clear
    map::count
    map::emplace, emplace_hint
    map::empty
    map::equal_range
    map::erase
    map::find
    map::get_allocator
    map::insert
    map::key_comp, value_comp
    map::upper_bound, lower_bound
    map::max_size
    map::operator=, operator[]
    map::size
    map::swap
    */

    map<int, int> m;
    m.insert({1,5});
    m.insert({2,56});
    m.insert({5,34});
    m.insert({1,7});
    for(auto x:m) cout<<x.first<<" "<<x.second<<"\n";
    if( m.find(2) != m.end())
        cout<<"found"<<"\n";
}

void multimap_demo(){
    // library - <map>
    /*
    Multimaps are associative containers that store elements formed by a combination of a key value and 
    a mapped value, following a specific order, and where multiple elements can have equivalent keys.
    */

    /*    
    multimap::begin, cbegin, rbegin, crbegin
    multimap::end, cend, rend, crend
    multimap::clear
    multimap::count
    multimap::emplace
    multimap::emplace_hint
    multimap::empty
    multimap::equal_range
    multimap::erase
    multimap::find
    multimap::get_allocator
    multimap::insert
    multimap::key_comp, value_comp
    multimap::upper_bound, lower_bound
    multimap::max_size
    multimap::operator=
    multimap::size
    multimap::swap
    */
    multimap<int, int> m;
    m.insert({1,5});
    m.insert({2,56});
    m.insert({5,34});
    m.insert({1,7});
    for(auto x:m) cout<<x.first<<" "<<x.second<<"\n";

    // rest is same as map
}

void unordered_map_demo(){
    //library = <unordered_map>
    
    /*
    Unordered maps are associative containers that store elements formed by the combination of a key value 
    and a mapped value, and which allows for fast retrieval of individual elements based on their keys.
    */


    /*    
    unordered_map::at
    unordered_map::begin, cbegin
    unordered_map::end, cend
    unordered_map::bucket
    unordered_map::bucket_count
    unordered_map::bucket_size
    unordered_map::clear
    unordered_map::count
    unordered_map::emplace
    unordered_map::emplace_hint
    unordered_map::empty
    unordered_map::equal_range
    unordered_map::erase
    unordered_map::find
    unordered_map::get_allocator
    unordered_map::hash_function
    unordered_map::insert
    unordered_map::key_eq
    unordered_map::load_factor
    unordered_map::max_bucket_count
    unordered_map::max_load_factor
    unordered_map::max_size
    unordered_map::operator=
    unordered_map::operator[]
    unordered_map::rehash
    unordered_map::reserve
    unordered_map::size
    unordered_map::swap
    */

    unordered_map<int,int> um;
    um.insert({1,5});
    um.insert({2,56});
    um.insert({5,34});
    um.insert({1,7});
    for(auto x:um) cout<<x.first<<" "<<x.second<<"\n";

    // rest is same as map


}

void unordered_mutimap_demo(){
    //library = <unordered_multimap>

    /*
    Unordered multimaps are associative containers that store elements formed by the combination of a key value 
    and a mapped value, much like unordered_map containers, but allowing different elements to have equivalent keys.
    */

    /*  
    unordered_multimap::begin, cbegin
    unordered_multimap::end, cend
    unordered_multimap::bucket
    unordered_multimap::bucket_count
    unordered_multimap::bucket_size
    unordered_multimap::clear
    unordered_multimap::count
    unordered_multimap::emplace
    unordered_multimap::emplace_hint
    unordered_multimap::empty
    unordered_multimap::equal_range
    unordered_multimap::erase
    unordered_multimap::find
    unordered_multimap::get_allocator
    unordered_multimap::hash_function
    unordered_multimap::insert
    unordered_multimap::key_eq
    unordered_multimap::load_factor
    unordered_multimap::max_bucket_count
    unordered_multimap::max_load_factor
    unordered_multimap::max_size
    unordered_multimap::operator=
    unordered_multimap::rehash
    unordered_multimap::reserve
    unordered_multimap::size
    unordered_multimap::swap
    */

    unordered_multimap<int,int> um;
    um.insert({1,5});
    um.insert({2,56});
    um.insert({5,34});
    um.insert({1,7});
    for(auto x:um) cout<<x.first<<" "<<x.second<<"\n";

    // rest is same as map
}

int main(){
    //Operators();

    //iterators();

    //array_demo();

    //vector_demo();

    //pair_demo();

    //tuple_demo();

    //stack_demo();

    //queue_demo();

    //priority_queue_demo();

    //deque_demo();

    //list_demo();

    //forward_list_demo();

    //set_demo();

    //multiset_demo();

    //unordered_set_demo();

    //unordered_multiset_demo();

    //map_demo();

    //multimap_demo();

    //unordered_map_demo();

    //unordered_mutimap_demo();

    return 0;
}
