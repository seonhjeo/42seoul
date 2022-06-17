/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:10:59 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/06/17 12:29:10 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "reverse_iterator.hpp"

# ifndef RED_
#  define RED_ true
# endif
# ifndef BLACK_
#  define BLACK_ false
# endif

namespace ft
{

template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
class map
{
public:
	/* node */
	typedef struct				s_node
	{
		ft::pair<const Key, T>	data;
		bool					color;
		struct s_node*			left;
		struct s_node*			right;
		struct s_node*			parent;

		s_node(ft::pair<const Key, T> data) : data(data)
		{}
		const Key& key() { return (data.first); }
		T& val() { return (data.second); }
	}							node;

	/* iterator subclass */
	template <bool IsConst>
	class mapIterator : public ft::iterator< ft::bidirectional_iterator_tag, ft::pair<const Key, T> >
	{
	public:
		/* Member types */
		typedef ft::pair<const Key, T>												pair_type;
		typedef typename ft::conditional<IsConst, const pair_type, pair_type>::type	value_type;
		typedef typename ft::conditional<IsConst, const node, node>::type			node_type;
		typedef std::ptrdiff_t														difference_type;
		typedef std::size_t															size_type;

		/* constructors, destructor */
		mapIterator() {
			_ptr = NULL;
		}
		mapIterator(node_type * const ptr) {
			_ptr = ptr;
		}
		~mapIterator() {}

		/* copy constructor */
		template <bool B>
		mapIterator (const mapIterator<B> & x, typename ft::enable_if<!B>::type* = 0) {
			_ptr = x.getPtr();
		}

		/* assignment */
		mapIterator & operator=(const mapIterator & x) {
			_ptr = x.getPtr();
			return (*this);
		}

		/* comparison */
		template <bool B>
		bool operator==(const mapIterator<B> & x) const {
			return (_ptr == x.getPtr());
		}
		template <bool B>
		bool operator!=(const mapIterator<B> & x) const {
			return (_ptr != x.getPtr());
		}

		/* increment, decrement */
		mapIterator& operator++() {
			this->nextNode();
			return (*this);
		}
		mapIterator& operator--() {
			this->prevNode();
			return (*this);
		}
		mapIterator operator++(int) {
			mapIterator<IsConst> x(*this);
			this->nextNode();
			return (x);
		}
		mapIterator operator--(int) {
			mapIterator<IsConst> x(*this);
			this->prevNode();
			return (x);
		}
		/* dereference */
		value_type& operator*() const {
			return (_ptr->data);
		}
		value_type* operator->() const {
			return (&_ptr->data);
		}
		/* member functions */
		node_type* getPtr() const {
			return (_ptr);
		}

	private:
		node_type* _ptr;

		void nextNode() {
			// if node has child in right(bigger)
			if (_ptr->right != _ptr->right->left)
			{
				_ptr = _ptr->right;
				while (_ptr->left != _ptr->left->left)
					_ptr = _ptr->left;
			}
			else
			{
				while (_ptr == _ptr->parent->right && _ptr != _ptr->parent)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
		}

		void prevNode() {
			// if node is root
			if (_ptr == _ptr->parent)
			{
				while (_ptr->right != _ptr->right->left)
					_ptr = _ptr->right;
			}
			// if node has child in left(smaller)
			else if (_ptr->left != _ptr->left->left)
			{
				_ptr = _ptr->left;
				while (_ptr->right != _ptr->right->left)
					_ptr = _ptr->right;
			}
			else
			{
				while (_ptr == _ptr->parent->left && _ptr != _ptr->parent)
					_ptr = _ptr->parent;
				_ptr = _ptr->parent;
			}
		}
	}; // Iterator

	/* Member typedef */
	class		ValueCompare;

	typedef	Key												key_type;
	typedef	T												mapped_type;
	typedef	ft::pair<const key_type, mapped_type>			value_type;
	typedef	Compare											key_compare;
	typedef	ValueCompare									value_compare;
	typedef	typename Alloc::template rebind<node>::other	allocator_type;
	typedef	typename allocator_type::reference				reference;
	typedef	typename allocator_type::const_reference		const_reference;
	typedef	typename allocator_type::pointer				pointer;
	typedef	typename allocator_type::const_pointer			const_pointer;
	typedef	mapIterator<false>								iterator;
	typedef	mapIterator<true>								const_iterator;
	typedef	ft::rev_map_iterator<iterator>					reverse_iterator;
	typedef	ft::rev_map_iterator<const_iterator>			const_reverse_iterator;
	typedef	typename mapIterator<false>::difference_type	difference_type;
	typedef	typename mapIterator<false>::size_type			size_type;


	/* value compare subclass */
	class ValueCompare {
	public:
		friend class		map;
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;

		bool operator()(const value_type & x, const value_type & y) const {
			return (comp(x.first, y.first));
		}
	protected:
		ValueCompare(Compare c) : comp(c) {}
		Compare comp;
	};

	/* constructors */
	explicit map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) {
		_alloc = alloc;
		_comp = comp;
		this->_new_nil_node();
	}

	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type(), typename ft::enable_if<!ft::is_same<InputIterator, int>::value>::type* = 0) {
		_alloc = alloc;
		_comp = comp;
		this->_new_nil_node();

		while (first != last)
			this->insert(*first++);
	}

	map (const map & x) {
		this->_new_nil_node();
		*this = x;
	}


	/* destructors */
	~map () {
		this->clear();
		_alloc.destroy(_nil);
		_alloc.deallocate(_nil, 1);
	}


	/* assignment operator */
	map& operator= (const map & x) {
		if (this == &x)
			return (*this);

		this->clear();
		_alloc = x._alloc;
		_comp = x._comp;
		this->_new_nil_node();

		for (const_iterator it = x.begin() ; it != x.end() ; it++)
			this->insert(*it);
		return (*this);
	}


	/* iterators */
	iterator begin () { return (iterator(this->_leftmost(_nil->right))); }
	const_iterator begin () const { return (const_iterator(this->_leftmost(_nil->right))); }
	iterator end () { return (iterator(_nil)); }
	const_iterator end () const { return (const_iterator(_nil)); }
	reverse_iterator rbegin () { return (reverse_iterator(_nil)); }
	const_reverse_iterator rbegin () const { return (const_reverse_iterator(_nil)); }
	reverse_iterator rend () { return (reverse_iterator(this->_leftmost(_nil->right))); }
	const_reverse_iterator rend () const { return (const_reverse_iterator(this->_leftmost(_nil->right))); }


	/* capacity */

	// Checks if the container has no elements
	bool empty () const { return (_nil == _nil->right); }

	// Returns the number of elements in the container
	size_type size () const {
		size_type n = 0;
		for (const_iterator it = this->begin() ; it != this->end() ; it++)
			n++;
		return (n);
	}

	// Returns the maximum number of elements the container is able to hold
	// due to system or library implementation limitations
	size_type max_size () const {
		return (_alloc.max_size());
	}

	/* member access type */

	// Returns a reference to the value that is mapped to a key equivalent to key,
	// performing an insertion if such key does not already exist.
	mapped_type & operator[] (const key_type & k) {
		this->insert(ft::make_pair(k, mapped_type()));
		return (this->find(k)->second);
	}

	/* Insertion modifiers */

	// Inserts element(s) into the container,
	// if the container doesn't already contain an element with an equivalent key.
	ft::pair<iterator,bool> insert (const value_type & val) {
		iterator it;
		if (this->count(val.first))
		{
			it = this->find(val.first);
			return (ft::make_pair(it, false));
		}
		else
		{
			it = iterator(this->_new_node(val));
			return (ft::make_pair(it, true));
		}
	}
	iterator insert (iterator position, const value_type & val) {
		(void)position;
		return (this->insert(val).first);
	}
	template <class InputIterator>
	void insert (InputIterator first, InputIterator last,
	typename ft::enable_if<!ft::is_same<InputIterator, int>::value>::type* = 0) {
		while (first != last)
			this->insert(*first++);
	}


	/* Erasure modifiers */
	// Removes specified elements from the container.

	// Removes the element at pos.
	void erase (iterator position) {
		node* ptr = position.getPtr();

		// if node has two children
		if (ptr->left != _nil && ptr->right != _nil) {
			position--;
			this->_swap_nodes(ptr, position.getPtr());
			this->erase(ptr);
		}
		// if node has one or no child
		else {
			node* child = (ptr->left != _nil) ? ptr->left : ptr->right;
			if (child != _nil)
				child->parent = ptr->parent;
			if (ptr->parent->left == ptr)
				ptr->parent->left = child;
			else
				ptr->parent->right = child;

			this->_removeNode(ptr, child);
		}
	}
	// Removes the element (if one exists) with the key equivalent to key
	size_type erase (const key_type & k) {
		if (this->count(k))
		{
			this->erase(this->find(k));
			return (1);
		}
		return (0);
	}
	// Removes the elements in the range [first; last), which must be a valid range in *this
	void erase (iterator first, iterator last) {
		for (iterator it = first++ ; it != last ; it = first++)
			this->erase(it);
	}


	/* Common modifiers */

	// Exchanges the contents of the container with those of other.
	// Does not invoke any move, copy, or swap operations on individual elements.
	void swap (map & x) {
		ft::swap(_alloc, x._alloc);
		ft::swap(_comp, x._comp);
		ft::swap(_nil, x._nil);
	}

	// Erases all elements from the container. After this call, size() returns zero.
	void clear () {
		iterator first = this->begin();
		for (iterator it = first++ ; it != this->end() ; it = first++)
			this->erase(it);
	}


	/* Observers */

	// Returns the function object that compares the keys
	// which is a copy of this container's constructor argument comp.
	key_compare key_comp () const { return (key_compare()); }

	// Returns a function object that compares objects of type std::map::value_type (key-value pairs)
	// by using key_comp to compare the first components of the pairs.
	value_compare value_comp () const { return (value_compare(_comp)); }


	/* Lookup operations */

	// Finds an element with key equivalent to key
	iterator find (const key_type & k) {
		if (this->count(k))
			return (iterator(this->_find_node(_nil->right, k)));
		else
			return (this->end());
	}
	const_iterator find (const key_type & k) const {
		if (this->count(k))
			return (const_iterator(this->_find_node(_nil->right, k)));
		else
			return (this->end());
	}

	// Returns the number of elements with key that compares equivalent to the specified argument
	// which is either 1 or 0 since this container does not allow duplicates.
	size_type count (const key_type & k) const {
		size_type n = 0;
		for (const_iterator it = this->begin() ; it != this->end() ; it++)
		{
			if (this->_equal(k, it->first))
				n++;
		}
		return (n);
	}

	// Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
	iterator lower_bound (const key_type & k) {
		iterator it = this->begin();
		while (this->_comp(it->first, k) && it != this->end())
			it++;
		return (it);
	}
	const_iterator lower_bound (const key_type & k) const {
		const_iterator it = this->begin();
		while (this->_comp(it->first, k) && it != this->end())
			it++;
		return (it);
	}

	// Returns an iterator pointing to the first element that is greater than key.
	iterator upper_bound (const key_type & k) {
		iterator it = this->begin();
		while (this->_comp(k, it->first) == false && it != this->end())
			it++;
		return (it);
	}
	const_iterator upper_bound (const key_type & k) const {
		const_iterator it = this->begin();
		while (this->_comp(k, it->first) == false && it != this->end())
			it++;
		return (it);
	}

	// Returns a range containing all elements with the given key in the container.
	// The range is defined by two iterators,
	// one pointing to the first element that is not less than key and another pointing to the first element greater than key.
	// Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
	ft::pair<iterator,iterator> equal_range (const key_type & k) {
		return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
	}

	ft::pair<const_iterator,const_iterator> equal_range (const key_type & k) const {
		return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
	}


	/* Allocator */
	// Returns the allocator associated with the container.
	allocator_type get_allocator () const { return (allocator_type()); }


private:
	/* Private functions */

	// make node '_nil', which defined as private member variable
	void _new_nil_node () {
		_nil = _alloc.allocate(1);
		this->_construct(_nil);
		_nil->color = BLACK_;
	}

	// make new node valued by 'val' and insert to tree
	node* _new_node (const value_type & val = value_type()) {
		node* new_node = _alloc.allocate(1);
		this->_construct(new_node, val);

		node* parent = this->_find_parent(_nil->right, val.first);
		if (parent == _nil || !this->_comp(val.first, parent->key()))
			parent->right = new_node;
		else
			parent->left = new_node;
		new_node->parent = parent;

		this->_insertRB(new_node);

		return (new_node);
	}

	// initialize node with given values
	void _construct (node* ptr, const value_type & val = value_type()) {
		node tmp(val);
		tmp.left = _nil;
		tmp.right = _nil;
		tmp.parent = _nil;
		tmp.color = RED_;
		_alloc.construct(ptr, tmp);
	}

	// swap nodes position
	void _swap_nodes (node* a, node* b) {
		if (a->left != b && a->left != _nil)
			a->left->parent = b;
		if (a->right != b && a->right != _nil)
			a->right->parent = b;
		if (a->parent != b && a->parent != _nil) {
			if (a->parent->left == a)
				a->parent->left = b;
			else
				a->parent->right = b;
		}

		if (b->left != a && b->left != _nil)
			b->left->parent = a;
		if (b->right != a && b->right != _nil)
			b->right->parent = a;
		if (b->parent != a && b->parent != _nil) {
			if (b->parent->left == b)
				b->parent->left = a;
			else
				b->parent->right = a;
		}

		if (a->parent == b)
			a->parent = a;
		if (a->left == b)
			a->left = a;
		if (a->right == b)
			a->right = a;
		if (b->parent == a)
			b->parent = b;
		if (b->left == a)
			b->left = b;
		if (b->right == a)
			b->right = b;

		ft::swap(a->parent, b->parent);
		ft::swap(a->left, b->left);
		ft::swap(a->right, b->right);
		ft::swap(a->color, b->color);

		if (_nil->right == a)
			_nil->right = b;
		else if (_nil->right == b)
			_nil->right = a;
	}

	// remove and destroy node 'ptr'
	void _removeNode (node* ptr, node* child)
	{
		this->_deleteRB(ptr, child);

		_alloc.destroy(ptr);
		_alloc.deallocate(ptr, 1);
	}

	// find child node which has key_type 'k' from node 'current', return '_nil' if failed
	node* _find_node (node* current, const key_type & k) const
	{
		if (current == _nil || this->_equal(current->key(), k))
			return (current);
		else if (this->_comp(k, current->key()))
			return (this->_find_node(current->left, k));
		else
			return (this->_find_node(current->right, k));
	}

	// find parent node which has key_type 'k' from node 'current', return '_nil' if failed
	node* _find_parent (node* current, const key_type& k) const
	{
		if (!this->_comp(k, current->key()))
		{
			if (current->right == _nil)
				return (current);
			else
				return (this->_find_parent(current->right, k));
		}
		else
		{
			if (current->left == _nil)
				return (current);
			else
				return (this->_find_parent(current->left, k));
		}
	}

	// return leftmost child node from 'root'
	node* _leftmost (node* root) const
	{
		while (root->left != root->left->left)
			root = root->left;
		return (root);
	}

	// return true if 'lhs' and 'rhs' is same
	bool _equal (const key_type & lhs, const key_type & rhs) const {
		return (this->_comp(lhs, rhs) == false && this->_comp(rhs, lhs) == false);
	}


	/* Red and Black Tree */

	// insert node with rule of RBTree
	void _insertRB (node* x)
	{
		node* parent = x->parent;
		node* grandparent = parent->parent;
		node* uncle = (grandparent->right == parent) ? grandparent->left : grandparent->right;

		// if x is root node
		if (parent == _nil)
			x->color = BLACK_;
		// if parent is black
		else if (parent->color == BLACK_)
			return ;
		// recoloring
		// recursively do fixing with grandparent
		else if (uncle->color == RED_)
		{
			parent->color = BLACK_;
			uncle->color = BLACK_;
			grandparent->color = RED_;
			this->_insertRB(grandparent);
		}
		// restructing (search wikipedia)
		// rotate nodes and change color
		else if (uncle->color == BLACK_)
		{
			if (grandparent->left->left == x || grandparent->right->right == x)
			{
				// fifth
				if (grandparent->left->left == x)
					this->_LL(grandparent, parent);
				// fifth-reverse
				else if (grandparent->right->right == x)
					this->_RR(grandparent, parent);
				ft::swap(grandparent->color, parent->color);
			}
			else
			{
				// fourth
				if (grandparent->left->right == x)
					this->_LR(grandparent, parent, x);
				//fourth-reverse
				else if (grandparent->right->left == x)
					this->_RL(grandparent, parent, x);
				ft::swap(grandparent->color, x->color);
			}
		}
	}

	// delete node with rule of RBTree
	void _deleteRB (node* v, node* u)
	{
		if (v->color == RED_ || u->color == RED_)
			u->color = BLACK_;
		else
			this->_doubleBlack(u, v->parent);
	}

	void _doubleBlack (node* u, node* parent)
	{
		node* sibling = (parent->left != u) ? parent->left : parent->right;

		if (u == _nil->right || u == _nil)
			return ;
		else if (sibling->color == BLACK_ && (sibling->left->color == RED_ || sibling->right->color == RED_))
		{
			if (sibling == parent->left && sibling->left->color == RED_)
				this->_LL(parent, sibling);
			else if (sibling == parent->left && sibling->right->color == RED_)
				this->_LR(parent, sibling, sibling->right);
			else if (sibling == parent->right && sibling->right->color == RED_)
				this->_RR(parent, sibling);
			else if (sibling == parent->right && sibling->left->color == RED_)
				this->_RL(parent, sibling, sibling->left);

			if (sibling->left->color == RED_)
				sibling->left->color = BLACK_;
			else
				sibling->right->color = BLACK_;
		}
		else if (sibling->color == BLACK_)
		{
			sibling->color = RED_;
			if (parent->color == RED_)
				parent->color = BLACK_;
			else
				this->_doubleBlack(parent, parent->parent);
		}
		else if (sibling->color == RED_)
		{
			if (sibling == parent->left)
				this->_LL(parent, sibling);
			else
				this->_RR(parent, sibling);
			ft::swap(parent->color, sibling->color);
			this->_doubleBlack(u, parent);
		}
	}

	// rotate nodes
	void _LL (node* grandparent, node* parent)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = parent;
		else
			grandparent->parent->left = parent;
		if (parent->right != _nil)
			parent->right->parent = grandparent;
		grandparent->left = parent->right;
		parent->parent = grandparent->parent;
		grandparent->parent = parent;
		parent->right = grandparent;
	}

	void _RR (node* grandparent, node* parent)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = parent;
		else
			grandparent->parent->left = parent;
		if (parent->left != _nil)
			parent->left->parent = grandparent;
		grandparent->right = parent->left;
		parent->parent = grandparent->parent;
		grandparent->parent = parent;
		parent->left = grandparent;
	}

	void _LR (node* grandparent, node* parent, node* x)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = x;
		else
			grandparent->parent->left = x;
		if (x->left != _nil)
			x->left->parent = parent;
		if (x->right != _nil)
			x->right->parent = grandparent;
		grandparent->left = x->right;
		parent->right = x->left;
		x->parent = grandparent->parent;
		grandparent->parent = x;
		parent->parent = x;
		x->left = parent;
		x->right = grandparent;
	}

	void _RL (node* grandparent, node* parent, node* x)
	{
		if (grandparent->parent->right == grandparent)
			grandparent->parent->right = x;
		else
			grandparent->parent->left = x;
		if (x->left != _nil)
			x->left->parent = grandparent;
		if (x->right != _nil)
			x->right->parent = parent;
		grandparent->right = x->left;
		parent->left = x->right;
		x->parent = grandparent->parent;
		grandparent->parent = x;
		parent->parent = x;
		x->left = grandparent;
		x->right = parent;
	}


	/* Member variables */
	allocator_type		_alloc;
	key_compare			_comp;
	node*				_nil;
}; // class Map

/* none-member operators */
template <class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs) {
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs) {
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs) {
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs) {
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key,T,Compare,Alloc> & lhs, const map<Key,T,Compare,Alloc> & rhs) {
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Alloc>
void swap(map<Key,T,Compare,Alloc> & x, map<Key,T,Compare,Alloc> & y) {
	x.swap(y);
}

}; // namespace ft

#endif
