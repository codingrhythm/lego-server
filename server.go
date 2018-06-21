package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
)

// Page is data structure
type Page struct {
	Title string
	Body  []byte
}

func loadPage(title string) (*Page, error) {
	filename := title + ".json"
	body, err := ioutil.ReadFile(filename)
	if err != nil {
		return nil, err
	}
	return &Page{Title: title, Body: body}, nil
}

func handler(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	title := r.URL.Path[1:]
	page, _ := loadPage(title)
	fmt.Fprintf(w, "%s", page.Body)
}

func main() {
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe(":8512", nil))
}
