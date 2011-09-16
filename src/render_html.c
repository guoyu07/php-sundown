/*
 * The MIT License
 *
 * Copyright (c) 2011 Shuhei Tanuma
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "php_sundown.h"
#include "html.h"

static void php_sundown_render_html_free_storage(php_sundown_render_html_t *obj TSRMLS_DC)
{
	zend_object_std_dtor(&obj->zo TSRMLS_CC);
	efree(obj);
}

zend_object_value php_sundown_render_html_new(zend_class_entry *ce TSRMLS_DC)
{
	zend_object_value retval;
	php_sundown_render_html_t *obj;
	zval *tmp;

	obj = ecalloc(1, sizeof(*obj));
	zend_object_std_init( &obj->zo, ce TSRMLS_CC);
	zend_hash_copy(obj->zo.properties, &ce->default_properties, (copy_ctor_func_t) zval_add_ref, (void *) &tmp, sizeof(zval *));
	
	retval.handle = zend_objects_store_put(obj, 
		(zend_objects_store_dtor_t)zend_objects_destroy_object,
		(zend_objects_free_object_storage_t)php_sundown_render_html_free_storage,
		NULL TSRMLS_CC);
	retval.handlers = zend_get_std_object_handlers();
	return retval;
}

zend_class_entry *sundown_render_html_class_entry;
extern zend_class_entry *sundown_render_base_class_entry;

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_enable_pants, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_block_code, 0, 0, 3)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, language)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_block_quote, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, quote)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_block_html, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, raw_html)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_header, 0, 0, 3)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, htext)
	ZEND_ARG_INFO(0, header_level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_hrule, 0, 0, 1)
	ZEND_ARG_INFO(0, buffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_list_box, 0, 0, 3)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, contents)
	ZEND_ARG_INFO(0, list_type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_list_item, 0, 0, 3)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, list_type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_paragraph, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_table, 0, 0, 3)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, header)
	ZEND_ARG_INFO(0, body)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_table_row, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_table_cell, 0, 0, 3)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, alignment)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_autolink, 0, 0, 3)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, link)
	ZEND_ARG_INFO(0, link_type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_codespan, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, code)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_double_emphasis, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_emphasis, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_image, 0, 0, 4)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, link)
	ZEND_ARG_INFO(0, title)
	ZEND_ARG_INFO(0, alt_text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_linebreak, 0, 0, 1)
	ZEND_ARG_INFO(0, buffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_link, 0, 0, 4)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, link)
	ZEND_ARG_INFO(0, title)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_raw_html, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, raw_html)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_triple_emphasis, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_strikethrough, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_superscript, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_entity, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_normal_text, 0, 0, 2)
	ZEND_ARG_INFO(0, buffer)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_doc_header, 0, 0, 1)
	ZEND_ARG_INFO(0, buffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_doc_footer, 0, 0, 1)
	ZEND_ARG_INFO(0, buffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_preprocess, 0, 0, 1)
	ZEND_ARG_INFO(0, full_document)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sundown_render_html_postprocess, 0, 0, 1)
	ZEND_ARG_INFO(0, full_document)
ZEND_END_ARG_INFO()

/* {{{ proto void enable_pants()
*/
PHP_METHOD(sundown_render_html, enable_pants)
{
	RETURN_FALSE;
}
/* }}} */

/* {{{ proto void block_code($code, $language)
*/
PHP_METHOD(sundown_render_html, block_code)
{
	char *code, *block_code;
	int code_len, block_code_len;
	zval *buffer;
	struct buf *input, *lang;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zss", &buffer,&code, &code_len, &block_code, &block_code_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	php_sundown_render_base_t *base = (php_sundown_render_base_t *) zend_object_store_get_object(getThis() TSRMLS_CC);\
	input = str2buf(block_code, block_code_len);
	lang = str2buf(code, code_len);
	html->cb.blockcode(object->buffer,input,lang, &base->html);
	bufrelease(input);
	bufrelease(lang);
}
/* }}} */

/* {{{ proto void block_quote($quote)
*/
PHP_METHOD(sundown_render_html, block_quote)
{
	char *quote;
	int quote_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer,&quote, &quote_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	php_sundown_render_base_t *base = (php_sundown_render_base_t *) zend_object_store_get_object(getThis() TSRMLS_CC);\
	input = str2buf(quote, quote_len);
	html->cb.blockquote(object->buffer,input, &base->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void block_html($raw_html)
*/
PHP_METHOD(sundown_render_html, block_html)
{
	char *raw;
	int raw_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer,&raw, &raw_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	php_sundown_render_base_t *base = (php_sundown_render_base_t *) zend_object_store_get_object(getThis() TSRMLS_CC);\
	input = str2buf(raw, raw_len);
	html->cb.blockhtml(object->buffer,input, &base->html);
	bufrelease(input);}
/* }}} */

/* {{{ proto void header($htext,$header_level)
*/
PHP_METHOD(sundown_render_html, header)
{
	char *htext;
	long htext_len, header_level;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zsl", &buffer,&htext, &htext_len, &header_level) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	php_sundown_render_base_t *base = (php_sundown_render_base_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	// why htext_len looks wiered? for now use strlen instead of htext_len
	input = str2buf(htext, strlen(htext));
	html->cb.header(object->buffer,input,header_level, &base->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void hrule()
*/
PHP_METHOD(sundown_render_html, hrule)
{
	zval *buffer;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"z", &buffer) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	html->cb.hrule(object->buffer,&html->html);
}
/* }}} */

/* {{{ proto void list_box($contents, $list_type)
*/
PHP_METHOD(sundown_render_html, list_box)
{
	char *contents, *list_type;
	int contents_len, list_type_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zss", &buffer, &contents, &contents_len, &list_type, &list_type_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	php_sundown_render_base_t *base = (php_sundown_render_base_t *) zend_object_store_get_object(getThis() TSRMLS_CC);\
	input = str2buf(contents, contents_len);
	// Todo
	html->cb.list(object->buffer,input,0, &base->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void list_item($text, $list_type)
*/
PHP_METHOD(sundown_render_html, list_item)
{
	char *text, *list_type;
	int text_len, list_type_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zss", &buffer,&text, &text_len, &list_type, &list_type_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	php_sundown_render_base_t *base = (php_sundown_render_base_t *) zend_object_store_get_object(getThis() TSRMLS_CC);\
	input = str2buf(text, text_len);
	// Todo
	html->cb.listitem(object->buffer,input,0, &base->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void paragraph($text)
*/
PHP_METHOD(sundown_render_html, paragraph)
{
	char *text;
	int text_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer,&text, &text_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	php_sundown_render_base_t *base = (php_sundown_render_base_t *) zend_object_store_get_object(getThis() TSRMLS_CC);\
	input = str2buf(text, text_len);
	html->cb.paragraph(object->buffer,input, &base->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void table($header, $body)
*/
PHP_METHOD(sundown_render_html, table)
{
	char *header, *body;
	int header_len, body_len;
	zval *buffer;
	php_sundown_buffer_t *object;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zss", &buffer, &header, &header_len, &body, &body_len) == FAILURE){
		return;
	}
	
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	bufput(object->buffer, body, body_len);
}
/* }}} */

/* {{{ proto void table_row($content)
*/
PHP_METHOD(sundown_render_html, table_row)
{
	char *contents;
	int contents_len;
	zval *buffer;
	php_sundown_buffer_t *object;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer,&contents, &contents_len) == FAILURE){
		return;
	}
	
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	bufput(object->buffer, contents, contents_len);
}
/* }}} */

/* {{{ proto void table_cell($content, $alignment)
*/
PHP_METHOD(sundown_render_html, table_cell)
{
	char *content, *alignment;
	int content_len, alignment_len;
	zval *buffer;
	php_sundown_buffer_t *object;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zss", &buffer,&content, &content_len, &alignment, &alignment_len) == FAILURE){
		return;
	}

	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	bufput(object->buffer, content, content_len);
}
/* }}} */

/* {{{ proto void autolink($link, $link_type)
*/
PHP_METHOD(sundown_render_html, autolink)
{
	char *link, *link_type;
	int link_len, link_type_len;
	zval *buffer;
	struct buf *m_link;
	php_sundown_buffer_t *object;
	//Todo: map types.
	enum mkd_autolink type = MKDA_NORMAL;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zss", &buffer,&link, &link_len, &link_type, &link_type_len) == FAILURE){
		return;
	}

	m_link = str2buf(link, link_len);
	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	html->cb.autolink(object->buffer,m_link,type, &html->html);
	bufrelease(m_link);
}
/* }}} */

/* {{{ proto void codespan($code)
*/
PHP_METHOD(sundown_render_html, codespan)
{
	char *code;
	int code_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer,&code, &code_len) == FAILURE){
		return;
	}

	input = str2buf(code, code_len);
	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	html->cb.codespan(object->buffer,input, &html->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void double_emphasis($text)
*/
PHP_METHOD(sundown_render_html, double_emphasis)
{
	char *text;
	int text_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer,&text, &text_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	php_sundown_render_base_t *base = (php_sundown_render_base_t *) zend_object_store_get_object(getThis() TSRMLS_CC);\
	input = str2buf(text, text_len);
	html->cb.double_emphasis(object->buffer,input, &base->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void emphasis($text)
*/
PHP_METHOD(sundown_render_html, emphasis)
{
	char *text;
	int text_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer,&text, &text_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	php_sundown_render_base_t *base = (php_sundown_render_base_t *) zend_object_store_get_object(getThis() TSRMLS_CC);\
	input = str2buf(text, text_len);
	html->cb.emphasis(object->buffer,input, &base->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void image($link, $title, $alt_text)
*/
PHP_METHOD(sundown_render_html, image)
{
	char *link, *title, *alt_text;
	int link_len, title_len, alt_text_len;
	zval *buffer;
	php_sundown_buffer_t *object;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zsss", &buffer,&link, &link_len, &title, &title_len, &alt_text, &alt_text_len) == FAILURE){
		return;
	}

	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	bufput(object->buffer, link, link_len);
}
/* }}} */

/* {{{ proto void linebreak()
*/
PHP_METHOD(sundown_render_html, linebreak)
{
	zval *buffer;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"z", &buffer) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	html->cb.linebreak(object->buffer,&html->html);
}
/* }}} */

/* {{{ proto void link($link,$title,$content)
*/
PHP_METHOD(sundown_render_html, link)
{
	char *link, *title, *content;
	int link_len, title_len, content_len;
	zval *buffer;
	struct buf *m_link, *m_title, *m_content;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zsss", &buffer,&link, &link_len, &title, &title_len, &content, &content_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	m_link = str2buf(link, link_len);
	m_title = str2buf(title, title_len);
	m_content = str2buf(content, content_len);
	html->cb.link(object->buffer,m_link, m_title, m_content, &html->html);
	bufrelease(m_link);
	bufrelease(m_title);
	bufrelease(m_content);
}
/* }}} */

/* {{{ proto void raw_html($raw_html)
*/
PHP_METHOD(sundown_render_html, raw_html)
{
	char *raw;
	int raw_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer,&raw, &raw_len) == FAILURE){
		return;
	}

	input = str2buf(raw, raw_len);
	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	html->cb.raw_html_tag(object->buffer,input, &html->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void triple_emphasis($text)
*/
PHP_METHOD(sundown_render_html, triple_emphasis)
{
	char *text;
	int text_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer,&text, &text_len) == FAILURE){
		return;
	}
	
	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	input = str2buf(text, text_len);
	html->cb.triple_emphasis(object->buffer,input, &html->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void strikethrough($text)
*/
PHP_METHOD(sundown_render_html, strikethrough)
{
	char *text;
	int text_len;
	zval *buffer;
	struct buf *input;
	php_sundown_render_html_t *html;
	php_sundown_buffer_t *object;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer,&text, &text_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	input = str2buf(text, text_len);
	html->cb.strikethrough(object->buffer,input, &html->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void superscript($text)
*/
PHP_METHOD(sundown_render_html, superscript)
{
	char *text;
	int text_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer,&text, &text_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	input = str2buf(text, text_len);
	html->cb.superscript(object->buffer,input, &html->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void entity($text)
*/
PHP_METHOD(sundown_render_html, entity)
{
	char *text;
	int text_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer, &text, &text_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	input = str2buf(text, text_len);
	html->cb.entity(object->buffer,input, &html->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void normal_text($text)
*/
PHP_METHOD(sundown_render_html, normal_text)
{
	char *text;
	int text_len;
	zval *buffer;
	struct buf *input;
	php_sundown_buffer_t *object;
	php_sundown_render_html_t *html;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"zs", &buffer, &text, &text_len) == FAILURE){
		return;
	}

	html = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	object = (php_sundown_buffer_t *) zend_object_store_get_object(buffer TSRMLS_CC);
	input = str2buf(text, text_len);
	html->cb.normal_text(object->buffer,input, &html->html);
	bufrelease(input);
}
/* }}} */

/* {{{ proto void doc_header()
*/
PHP_METHOD(sundown_render_html, doc_header)
{
	RETURN_FALSE;
}
/* }}} */

/* {{{ proto void doc_footer()
*/
PHP_METHOD(sundown_render_html, doc_footer)
{
	RETURN_FALSE;
}
/* }}} */

/* {{{ proto void preprocess($full_document)
*/
PHP_METHOD(sundown_render_html, preprocess)
{
	char *text;
	int text_len;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"s", &text, &text_len) == FAILURE){
		return;
	}
	
	RETURN_STRINGL(text,text_len, 1);
}
/* }}} */

/* {{{ proto void postprocess($full_document)
*/
PHP_METHOD(sundown_render_html, postprocess)
{
	char *text;
	int text_len;
	
	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
		"s", &text, &text_len) == FAILURE){
		return;
	}
	
	RETURN_STRINGL(text,text_len, 1);
}
/* }}} */

PHP_METHOD(sundown_render_html, __construct)
{
	php_sundown_render_html_t *object;
	struct php_sundown_renderopt_ex opt;

	object = (php_sundown_render_html_t *) zend_object_store_get_object(getThis() TSRMLS_CC);
	sdhtml_renderer(&object->cb, &opt.html, 0);
	opt.self = getThis();
}
	

static zend_function_entry php_sundown_render_html_methods[] = {
	PHP_ME(sundown_render_html, __construct,     arginfo_sundown_render_html___construct,     ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, enable_pants,    arginfo_sundown_render_html_enable_pants,    ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, block_code,      arginfo_sundown_render_html_block_code,      ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, block_quote,     arginfo_sundown_render_html_block_quote,     ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, block_html,      arginfo_sundown_render_html_block_html,      ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, header,          arginfo_sundown_render_html_header,          ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, hrule,           arginfo_sundown_render_html_hrule,           ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, list_box,        arginfo_sundown_render_html_list_box,        ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, list_item,       arginfo_sundown_render_html_list_item,       ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, paragraph,       arginfo_sundown_render_html_paragraph,       ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, table,           arginfo_sundown_render_html_table,           ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, table_row,       arginfo_sundown_render_html_table_row,       ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, table_cell,      arginfo_sundown_render_html_table_cell,      ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, autolink,        arginfo_sundown_render_html_autolink,        ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, codespan,        arginfo_sundown_render_html_codespan,        ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, double_emphasis, arginfo_sundown_render_html_double_emphasis, ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, emphasis,        arginfo_sundown_render_html_emphasis,        ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, image,           arginfo_sundown_render_html_image,           ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, linebreak,       arginfo_sundown_render_html_linebreak,       ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, link,            arginfo_sundown_render_html_link,            ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, raw_html,        arginfo_sundown_render_html_raw_html,        ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, triple_emphasis, arginfo_sundown_render_html_triple_emphasis, ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, strikethrough,   arginfo_sundown_render_html_strikethrough,   ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, superscript,     arginfo_sundown_render_html_superscript,     ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, entity,          arginfo_sundown_render_html_entity,          ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, normal_text,     arginfo_sundown_render_html_normal_text,     ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, doc_header,      arginfo_sundown_render_html_doc_header,      ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, doc_footer,      arginfo_sundown_render_html_doc_footer,      ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, preprocess,      arginfo_sundown_render_html_preprocess,      ZEND_ACC_PUBLIC)
	PHP_ME(sundown_render_html, postprocess,     arginfo_sundown_render_html_postprocess,     ZEND_ACC_PUBLIC)
	{NULL,NULL,NULL}
};

void php_sundown_render_html_init(TSRMLS_D)
{
	zend_class_entry ce;
	INIT_NS_CLASS_ENTRY(ce, ZEND_NS_NAME("Sundown","Render"),"HTML", php_sundown_render_html_methods);
	sundown_render_html_class_entry = zend_register_internal_class_ex(&ce, sundown_render_base_class_entry, NULL TSRMLS_CC);
	sundown_render_html_class_entry->create_object = php_sundown_render_html_new;
}