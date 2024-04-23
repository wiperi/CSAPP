import requests
from bs4 import BeautifulSoup


def extract_c_urls(url):
    """Extracts all URLs ending with .c from the given webpage.

    Args:
        url: The URL of the webpage to scrape.

    Returns:
        A list of URLs ending with .c found on the webpage.
    """
    try:
        response = requests.get(url)
        response.raise_for_status()  # Raise an exception for unsuccessful requests

        soup = BeautifulSoup(response.content, "html.parser")

        # Find all anchor tags (<a>)
        links = soup.find_all("a")

        c_urls = []
        for link in links:
            # Extract the href attribute (URL)
            href = link.get("href")
            if href and (href.endswith(".c") or href.endswith(".s")):  # Check if it ends with ".c"
                c_urls.append(href)

        return c_urls
    except requests.exceptions.RequestException as e:
        print(f"Error fetching webpage: {e}")
        return []


# Example usage
url = "https://cgi.cse.unsw.edu.au/~cs1521/23T3/topic/mips_data/code/"  # Replace with the actual URL
c_urls = extract_c_urls(url)

if c_urls:
    print("Extracted URLs ending with .c:")
    for url in c_urls:
        print(url)
else:
    print("No URLs ending with .c found on the webpage.")
